# Saarland C++ Programming Coursework

Solutions and notes for the **C++ Programming Course** at Saarland University (Chair for Clinical Bioinformatics). The repository mirrors the official assignments and follows their I/O formats, error handling, and testing conventions so that the provided pipelines pass.&#x20;

> Instructor: Pascal Hirsch • Semester: 2025 • Tooling: Unix-like shell + g++/CMake/CLion (or VS Code) • GitLab CI used for automated checks.&#x20;

---

## Repository layout

```
cpp-saarland-coursework/
├── assignment0/
│   └── test/                 # unzipped CMS test.zip tree (mandatory)
├── assignment1/
│   ├── code/                 # task2a.cpp, task2b.cpp, task{3,4,5,6}.cpp
│   └── test_files/           # examples + .solution.txt
├── assignment2/
│   ├── code/                 # SimpleNode, Dataframe, Needleman–Wunsch, etc.
│   └── test_files/
├── assignment3/
│   ├── code/                 # STL/iterators, n-skip-k-mers, Matrix iterators
│   └── test_files/
└── assignment4/
    ├── code/                 # Beamer/Catapult, Munkres, Bloom filter, Cliques
    └── test_files/
```

---

## Build & run

### Simple one-file tasks

```bash
g++ -std=c++17 -O2 task3.cpp -o task3
./task3 < input.txt > out.txt
cmp out.txt task3.solution.txt
```

(Use the exact I/O/CLI specified in each task; whitespace matters in automated tests.)&#x20;

### CLion / CMake

Open the provided `CMakeLists.txt` (where present) to build and debug. For low-level practice, you can also compile and link manually:

```bash
g++ -c main.cpp         # produces main.o
g++ main.o -o main      # links to executable
```



---

## Testing

* Each assignment ships **example inputs/solutions** under `test_files/`. Use redirection and `cmp` to compare your output exactly.
  Example: `./task2a > task2a.out && cmp task2a.out task2a.solution.txt`.&#x20;
* CI runs similar checks; trailing spaces or extra newlines will fail tests.&#x20;
* Beginning with **Assignment 2**, invalid input is tested; implementations must *validate*, print an error message, and exit with code `1` where specified.&#x20;

---

## Assignment 0 — Onboarding & Tooling

* **Task 0:** Read the “General remarks” rules (coding style, submission etiquette).&#x20;
* **Task 1:** GitLab setup: clone, add `.gitignore`, push, verify 3 green checks.&#x20;
* **Task 2:** Essential shell commands (`pwd`, `touch`, `vim`, `less`, `cp`, `mv`, `ls`, `mkdir`, `rm -r`).&#x20;
* **Task 3:** SSH to CIP pool; generate keys (`ssh-keygen`), copy with `ssh-copy-id`.&#x20;
* **Task 4:** Debug the 4 “handson\_code” snippets (compile, run, inspect).&#x20;
* **Task 5:** Manual compile/link with `g++` or via IDE.&#x20;

> Note: unzip the CMS `test.zip` into `assignment0/test/` *and commit the tree as-is* to pass the pipeline.&#x20;

---

## Assignment 1 — Warm-up (I/O, strings, FASTA, stats)

* **Task 1 (theory):** Types, expressions vs. statements, type safety, refs vs. pointers, pass-by-value/reference, declaration vs. definition, namespaces, error kinds, free store, RAII.&#x20;
* **Task 2 (2 parts):** Fix `task2a.cpp` & `task2b.cpp` to match example outputs.&#x20;
* **Task 3:** For multiple lines of **equal-length strings**, compute **min/max/mean/median Hamming distance** of the *nth* string vs. others, plus **count of substring k** (overlaps allowed, per-line). `n` and `k` via argv. If `n` out of range → print empty line.&#x20;
* **Task 4:** For lines of numbers: print **sum**, **digit sum of the sum**, **third quartile** (Q3 per Wikipedia method 1), **nth smallest** and **mth largest**; report `In`/`Im`/`Iq` when undefined. Also, print two extra lines with **Kaprekar** and **Lychrel** numbers (order preserved; empty lines if none). `n`, `m` via argv.&#x20;
* **Task 5:** Treat input as a **square matrix of strings**; compute the same Hamming/substring stats per **row**, **column**, **main diagonal**, and **upper triangle** (incl. diagonal; `n` from first row). `n`, `k` via argv.&#x20;
* **Task 6:** Given a **FASTA**, verify DNA/RNA, convert RNA→DNA, and for each valid sequence print the **next lexicographic permutation** (if it exists). Sort outputs by **length**, then lexicographically among equal lengths.&#x20;

---

## Assignment 2 — Classes, copying/moving, DP, heterogeneous tables

* **Task 1 (theory):** `const` vs `static`, const-correctness, `inline`, destructors, virtuals/pure virtual, multiple inheritance pitfalls.&#x20;
* **Task 2:** `SimpleNode` (singly linked list in `unique_ptr`): full **Rule of Five**, `insert`, `next`, `is_tail`, `length`, `operator()`. Deep copy semantics for copy ops.&#x20;
* **Task 3:** **Gene clustering** by chromosome and middle-position distance ≤ `d`; input `chr start stop` (sorted required), output with `cluster=i` appended; enforce coordinate order; error & exit code `1` if input isn’t sorted.&#x20;
* **Task 4:** **Needleman–Wunsch** (match `+1`, mismatch/gap `-1`): print best score and **all** optimal **global alignments** (separated by empty line).&#x20;
* **Task 5:** `Dataframe` with internal `std::list<std::vector<ColType>>` and **typed columns**: named rows/cols, `get<T>` by index or name (return references), add/remove/swap columns, `apply`, `order_by`, `<<`, `==`/`!=`. Throw exceptions on invalid usage.&#x20;

---

## Assignment 3 — STL/algorithms, hashing, custom iterators

* **Task 1 (theory):** `typedef` vs `using`, iterator categories & invalidation, container choice, “not found” conventions, `std::sort` comparator, why `set` has no `[]`.&#x20;
* **Task 2:** **STL-heavy pipeline**: generate `V1` and `V2` with **negative binomial** (MT19937\_64, seeds `s` and `2s`), compute **mean** & **sample std**, transform by `log2(|x|+1)`, print top-k, run **two-sample t-tests** (scaled & unscaled), shuffle 1…n (seed `7s`), multiply with unsorted scaled `V1`, and sort by **parity of nearest integer** (even-desc, then odd-asc). Validate argv; on invalid → error & exit 1. Output precision `3`.&#x20;
* **Task 3:** **n-skip-k-mers** from DNA FASTA: for each header, print `k-mer count` lines sorted by k-mer (case-insensitive); invalid sequences → print header to **stderr**. Performance targets: `<2s` for `k=10,n=1`, `<1min` for `k=33,n=1` on CIP pool; consider base-4 hashing.&#x20;
* **Task 4:** Extend `Matrix` with **reverse column iterators** and **diagonal iterators** (also `const_*` variants). Support `*it`, `++it`, `==/!=`. Valid only on square matrices for diagonal.&#x20;

---

## Assignment 4 — Greedy/coverage, O(n³) matching, probabilistic DS, graph search

* **Task 1 (theory):** references vs return-by-value risks, implicit interfaces (compile-time polymorphism), range member functions, set key mutation, pure predicates, lambda captures, `std::move`/`std::forward`, ordering of `std::set<std::string*>`.&#x20;
* **Task 2:** **Coverage** on a line of `n` cities with existing **beamers (range < k)** and optional **catapults (range < l)**: compute minimal enabled beamers and minimal catapults to cover all cities; print `-1` if impossible. Input: first line `n k l`, second line `c₁…cₙ` with `c∈{0,1,2}`.&#x20;
* **Task 3:** **Munkres (Hungarian) algorithm** `O(n³)` for the assignment problem; return a 0/1 assignment matrix. Follow Algorithm 2 of Riesen & Bunke (as referenced).&#x20;
* **Task 4:** **Bloom filter**: templated `BloomFilter<Key, m, Hash>` using `std::bitset<m>` and **MurmurHash**; ctor overloads, `insert`, `contains`, empirical **false positive rate**, **space ratio**, and **approx\_size** via `n* = - (m/k) ln(1 - X/m)`.&#x20;
* **Task 5:** **Bron–Kerbosch** to enumerate all **maximal cliques** from an adjacency matrix (read with the provided `Matrix` class); print each clique as `{i, j, ...}`.&#x20;

---

## Notes & conventions

* **Whitespace & formatting** are part of the API: match the exact output format in samples.&#x20;
* Where the sheet mandates it, **invalid inputs** must trigger an **error message** and **exit code 1**.&#x20;
* Use **`-std=c++17`** (or newer), enable warnings (`-Wall -Wextra -Wpedantic`) and test under a Unix-like shell.

---

## Acknowledgements

Assignments and problem statements © Chair for Clinical Bioinformatics, Saarland University. See the merged brief for full specifications and examples.&#x20;
