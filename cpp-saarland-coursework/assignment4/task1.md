### 1.  Why is it dangerous to return a reference when you must return an object?


Returning a **reference** to a **local variable** (inside a function) is dangerous because once the function exits, that local variable **goes out of scope**, and the reference will point to **invalid memory**. This causes **undefined behavior**.

** Safer alternative:** Return by value or use smart pointers if ownership/lifetime must be extended.

---

### 2.  What is an implicit interface in the context of compile-time polymorphism?



An **implicit interface** is not explicitly declared like an abstract base class. Instead, in **templates**, a class or function is expected to have certain methods or behaviors, and the compiler checks for these **during compilation**.

** Example:** If you pass a class to a template expecting a `.begin()` method, it must have one — even though there's no formal interface declaration.

---

### 3.  Why should you prefer range member functions to their single-element counterparts?



Using **range-based functions** like `insert(begin, end)` or `erase(first, last)` is often **more efficient** because:

* They **avoid multiple calls** and **redundant checks**.
* They're typically **better optimized** under the hood.

It’s like doing your shopping in one go instead of buying one item per trip.

---

### 4.  Why should you avoid in-place modification of keys in a set?



A `std::set` is ordered based on its keys. If you change a key **in-place**, the internal order becomes **corrupted**, and this breaks the **invariants** of the set. You might end up with a set that behaves unpredictably (e.g., missing elements).

** Instead:** Remove the element, modify it, then re-insert it.

---

### 5.  Why should predicate functions be pure?



Predicate functions (used in filters, sorts, etc.) should be **pure**, meaning they:

* Have **no side effects**
* Always return the same result for the same input

This ensures predictable behavior, easier debugging, and compatibility with **algorithms** expecting safe and deterministic comparisons.

---

### 6.  Why should you avoid the default capture modes of lambdas?



Default captures like `[=]` or `[&]` may silently include variables you didn’t mean to capture, which can lead to:

* **Unintended side effects**
* **Lifetime issues** (dangling references)
* **Hard-to-debug bugs**

** Best practice:** Be explicit with your captures (e.g., `[x, &y]`) so you know exactly what’s going on.

---

### 7. What do `std::move` and `std::forward` do?



* `std::move(obj)` **casts** an object to an r-value, enabling **move semantics** (instead of copying).
* `std::forward<T>(obj)` preserves the value category (lvalue/rvalue) during **perfect forwarding** in templates.

Think of `std::move` as “**give away ownership**,” while `std::forward` says “**pass along as-is**.”

---

### 8.  How are the strings of a `std::set<std::string*>` sorted? How would you sort them lexicographically?



By default, a `std::set<std::string*>` compares **pointers**, not the actual strings — so sorting is by **memory address**, not alphabet.

** To sort lexicographically**, provide a custom comparator:

```cpp
std::set<std::string*, bool(*)(const std::string*, const std::string*)> mySet(
    [](const std::string* a, const std::string* b) {
        return *a < *b;
    }
);
```

This way, it compares the **content** of the strings, not the pointers.

---

