import os, re, time, argparse
from urllib.parse import urlparse
from playwright.sync_api import sync_playwright, TimeoutError as PWTimeout
from playwright._impl._errors import Error as PWError

CF = "https://codeforces.com"
LANG_EXT = {
    "gnu c++": ".cpp","gnu c++17": ".cpp","gnu c++20": ".cpp","c++": ".cpp",
    "clang++": ".cpp","ms c++": ".cpp","python": ".py","python 3": ".py","pypy": ".py",
    "java": ".java","kotlin": ".kt","go": ".go","rust": ".rs","c#": ".cs","c11": ".c","c99": ".c",
    "javascript": ".js","node.js": ".js",
}

def safe(s): return re.sub(r"[^A-Za-z0-9_.-]+","_", s or "").strip("_")
def ext_from_lang(lang):
    l = (lang or "").lower()
    for k,v in LANG_EXT.items():
        if k in l: return v
    return ".txt"

def goto(page, url):
    for _ in range(3):
        try:
            page.goto(url, wait_until="domcontentloaded", timeout=45000)
            return True
        except PWError:
            time.sleep(0.6)
    print(f"  [warn] goto failed: {url}")
    return False

def ensure_en(page): goto(page, f"{CF}/?locale=en")

def ensure_entered(page, contest_url):
    if not goto(page, contest_url): return
    for sel in ['a:has-text("Enter")',
                'input[type="submit"][value*="Enter"]',
                'button:has-text("Enter")']:
        loc = page.locator(sel)
        if loc.count():
            try:
                loc.first.click(timeout=4000)
                page.wait_for_load_state("domcontentloaded", timeout=15000)
            except Exception:
                pass

def pick_logged_in_context(browser):
    for ctx in browser.contexts:
        for pg in ctx.pages:
            if "codeforces.com" in pg.url:
                return ctx
    return browser.contexts[0] if browser.contexts else browser.new_context()

def contest_root(contest_url: str) -> str:
    # e.g. https://codeforces.com/group/<hash>/contest/219158 -> return same (no trailing slash)
    m = re.search(r"^(.*?/contest/\d+)", contest_url.rstrip("/"))
    return m.group(1) if m else contest_url.rstrip("/")

def parse_my_table(page, debug=False):
    """Return rows (id, href (optional), prob, lang, accepted) from current /my page."""
    try:
        table = page.locator("table.status-frame-datatable")
        table.wait_for(state="visible", timeout=10000)
    except PWTimeout:
        if debug: print("  [debug] no table found on this page")
        return []

    rows = table.locator("tbody > tr")
    n = rows.count()
    if debug: print(f"  [debug] rows on page: {n}")

    out = []
    for i in range(n):
        r = rows.nth(i)
        tds = r.locator("td")
        if tds.count() < 6:
            if debug: print(f"    [debug] row {i}: too few tds ({tds.count()})")
            continue

        # --- Submission ID: read text from first td; if link exists, great; else just text ---
        sid = (tds.nth(0).inner_text() or "").strip()
        sid = re.search(r"\d+", sid).group(0) if re.search(r"\d+", sid) else ""
        if not sid:
            if debug: print(f"    [debug] row {i}: no numeric submission id in first cell")
            continue

        # --- Problem short label (from problem cell link text first token) ---
        pcell = tds.nth(3).locator('a[href*="/problem/"]')
        prob_txt = (pcell.first.text_content() or "").strip() if pcell.count() else (tds.nth(3).inner_text() or "").strip()
        prob = (prob_txt.split() or ["Problem"])[0]
        prob = safe(prob)

        # --- Language (5th column typically) ---
        lang = (tds.nth(4).text_content() or "").strip()

        # --- Verdict (6th column) ---
        vcell = tds.nth(5)
        verdict_ok = vcell.locator("span.verdict-accepted").count() > 0
        if not verdict_ok:
            vt = (vcell.text_content() or "").lower()
            verdict_ok = ("accepted" in vt) or (vt.strip() == "ok")
        if not verdict_ok:
            if debug: print(f"    [debug] row {i}: not accepted")
            continue

        out.append({"sub_id": sid, "prob": prob, "lang": lang})
        if debug: print(f"    [debug] row {i}: AC id={sid} prob={prob} lang={lang}")
    return out

def fetch_source_by_id(context, contest_root_url, sub_id):
    # Builds /submission/<id> under the same group/contest root
    url = f"{contest_root_url}/submission/{sub_id}"
    p = context.new_page()
    try:
        if not goto(p, url): return None
        pre = p.locator("pre#program-source-text")
        pre.wait_for(state="visible", timeout=15000)
        return pre.inner_text()
    except PWTimeout:
        return None
    finally:
        p.close()

def contest_dir(root, url):
    cid  = url.rstrip("/").split("/")[-1]
    m = re.search(r"/group/([^/]+)/contest", url)
    gtag = f"group_{m.group(1)[:8]}_" if m else ""
    d = os.path.join(root, f"{gtag}contest_{cid}")
    os.makedirs(d, exist_ok=True)
    return d

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--handle", required=True)
    ap.add_argument("--contests", required=True)
    ap.add_argument("--out", default="codeforces")
    ap.add_argument("--debug", action="store_true")
    args = ap.parse_args()

    with open(args.contests, "r", encoding="utf-8") as f:
        contests = [l.strip() for l in f if l.strip()]

    out_root = os.path.abspath(args.out)
    os.makedirs(out_root, exist_ok=True)

    with sync_playwright() as p:
        # NEW (use a persistent Edge profile)
        context = p.chromium.launch_persistent_context(
            user_data_dir="D:\\edge-cf-profile",  # any writable folder; persists login
            channel="msedge",                      # use Microsoft Edge
            headless=False
        )
        page = context.new_page()

        for c in contests:
            print(f"[info] Contest: {c}")
            ensure_entered(page, c)
            root = contest_root(c)
            saved = 0
            page_no = 1
            while True:
                url = c.rstrip("/") + ("/my" if page_no == 1 else f"/my?page={page_no}")
                if not goto(page, url): break
                if args.debug: print(f"  [debug] URL: {url}  title: {page.title()!r}")
                rows = parse_my_table(page, debug=args.debug)
                if not rows:
                    break

                out_dir = contest_dir(out_root, c)
                for R in rows:
                    ext = ext_from_lang(R["lang"])
                    out_path = os.path.join(out_dir, f"{R['prob']}_{R['sub_id']}{ext}")
                    if os.path.exists(out_path):
                        if args.debug: print(f"  [debug] skip exists {out_path}")
                        continue
                    src = fetch_source_by_id(context, root, R["sub_id"])
                    if not src:
                        print(f"  [warn] fetch failed {R['sub_id']}")
                        continue
                    with open(out_path, "w", encoding="utf-8") as f: f.write(src)
                    print(f"  [save] {out_path}")
                    saved += 1

                page_no += 1
                time.sleep(0.2)

            if saved == 0:
                print("  [info] No new accepted submissions.")

        # NEW shutdown
        page.close()
        context.close()


if __name__ == "__main__":
    main()
