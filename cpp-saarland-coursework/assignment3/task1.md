

### 1. **`typedef` vs `using`** 

Both `typedef` and `using` allow us to create type aliases, which is like giving a nickname to a complicated type. But `using` is newer (C++11+) and plays nicer with templates.

* **`typedef`** example:

  ```cpp
  typedef std::vector<std::pair<int, std::string>> IDNameVec;
  ```

* **`using`** example:

  ```cpp
  using IDNameVec = std::vector<std::pair<int, std::string>>;
  ```

*Why use `using`?* It’s more readable and supports template aliasing, something `typedef` can’t do.

---

### 2. **What are iterators? Name 3 types + uses** 

Iterators are like smart pointers that know how to walk through containers in C++. They abstract how we move through elements, regardless of the container's internal structure.

**3 types of iterators:**

* **Input Iterator**: Reads data *once*, like a one-way street (e.g., reading from `std::cin`).
*  **Forward Iterator**: Moves forward multiple times, reusable. E.g., `std::forward_list`.
*  **Bidirectional Iterator**: Goes forward *and* backward. Think of a `std::list`.

---

### 3. **Crucial difference: input vs forward iterator** 

An **input iterator** can only *read once* from an element (like a stream), while a **forward iterator** can be used to *read multiple times* from the same element. That makes input iterators more "disposable" and forward iterators more "reliable."

---

### 4. **Why does `std::vector` invalidate iterators with insert/push\_back/erase?** 

Because a vector stores elements in a dynamic array. When you insert or push beyond capacity, it might resize and move everything to a new memory location. Old iterators? Pointing to ghosts now. 

---

### 5. **Choosing the right STL container** 

| Scenario                                   | Container            | Why                                                      |
| ------------------------------------------ | -------------------- | -------------------------------------------------------- |
| a) Sorted traversal, no duplicates         | `std::set`           | Keeps elements sorted, enforces uniqueness               |
| b) No order, no duplicates                 | `std::unordered_set` | Faster access (hash-based), no sorting overhead          |
| c) Add to end + fast traversal             | `std::vector`        | Appending is fast, memory is contiguous = fast iteration |
| d) Dictionary with multiple values per key | `std::multimap`      | Allows duplicate keys with sorted keys                   |

---

### 6. **How does STL algorithm show “not found” or failure?** 

Most STL algorithms return the **end iterator** (e.g., `container.end()`) if the element wasn’t found. It’s their subtle way of saying “nope, not here.” 

---

### 7. **What does `std::sort(b, e)` use for sorting?** 

It uses the **`<` operator** (`operator<`) by default to compare elements. If you're sorting your own types, make sure you define what `<` means for them!

---

### 8. **Why doesn't `std::set` have `[]` operator?** 

Because `[]` usually means “insert or access,” but `std::set` is just a *set of values* — no key-value pair like a map. Allowing `[]` would risk breaking its *no duplicates* and *sorted order* rules.
