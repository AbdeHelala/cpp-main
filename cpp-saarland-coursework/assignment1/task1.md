## 1. Six Built-in C++ Types

1. **`int`**
   Used for integers (e.g., `10`, `-7`).

2. **`float`**
   Single-precision floating-point numbers (e.g., `2.5f`).

3. **`double`**
   Double-precision floating-point numbers (e.g., `3.14159`).

4. **`char`**
   Represents single characters (e.g., `'B'`, `'c'`).

5. **`bool`**
   Logical type with values `true` or `false`.

6. **`void`**
   Indicates absence of a type; typically for functions returning no value.

---

## 2. Expression vs. Statement

* **Expression**
  A code segment that evaluates to a value.

  ```cpp
  3 + y // computes and returns a numeric result
  ```

* **Statement**
  A complete instruction executed by the program, ending with a semicolon.

  ```cpp
  int total = 3 + y; // assigns the computed value to variable total
  ```

---

## 3. Type Safety

Type safety ensures variables are only used according to their declared types, avoiding errors and unpredictable behaviors.

* **Importance**

  * Reduces runtime errors
  * Enhances code readability and reliability
  * Enables early detection of type-related errors

---

## 4. References and Pointers

### References

* Provide an alternative name (alias) for an existing object.
* Must be initialized at declaration and cannot change reference later.

  ```cpp
  int num = 25;
  int& refNum = num; // refNum refers to num
  refNum = 35; // num is now 35
  ```

### Pointers

* Variables storing memory addresses of other objects.
* Can be reassigned and point to nothing (`nullptr`).

  ```cpp
  int num = 15;
  int* ptrNum = &num; // ptrNum points to num
  *ptrNum = 45; // num becomes 45
  ```

| Feature      | Reference (`&`) | Pointer (`*`)    |
| ------------ | --------------- | ---------------- |
| Rebindable?  | No              | Yes              |
| Syntax       | direct access   | indirect via `*` |
| Can be null? | No              | Yes (`nullptr`)  |

---

## 5. Pass by Value vs. Pass by Reference

### Pass by Value

* Provides a function with a copy of the input value.
* Changes inside the function do not affect the original.

  ```cpp
  void increment(int num) {
    num++;
  }

  int val = 10;
  increment(val);
  // val remains 10
  ```

### Pass by Reference

* Gives direct access to the caller's variable.
* Changes within the function affect the original.

  ```cpp
  void increment(int& num) {
    num++;
  }

  int val = 10;
  increment(val);
  // val is now 11
  ```

---

## 6. Declaration vs. Definition

* **Declaration**
  Introduces a name and type without allocating resources.

  ```cpp
  extern int counter; // declaration
  void process(int); // function declaration
  ```

* **Definition**
  Allocates memory or provides implementation.

  ```cpp
  int counter = 0; // definition
  void process(int x) { /* implementation */ }
  ```

---

## 7. Namespace

Namespaces group identifiers into a distinct named scope to prevent naming conflicts.

```cpp
namespace Geometry {
  double area(double radius) { return 3.14 * radius * radius; }
}

// usage
Geometry::area(5.0);
```

* **Purpose:**

  * Avoids naming collisions
  * Organizes logically related code

---

## 8. Four Error Categories

1. **Compile-time Errors**
   Occur due to syntax or incorrect type usage.

   ```cpp
   int val = "error"; // type mismatch error
   ```

2. **Link-time Errors**
   Occur when linking compiled files if definitions are missing.

   ```cpp
   void doSomething(); // declared, not defined anywhere
   ```

3. **Run-time Errors**
   Happen during program execution, e.g., invalid memory access.

   ```cpp
   int* num = nullptr;
   *num = 10; // segmentation fault
   ```

4. **Logical Errors**
   Code runs successfully but provides incorrect results.

   ```cpp
   int multiply(int a, int b) { return a + b; } // incorrect logic
   ```

---

## 9. Free Store (Heap)

Memory dynamically managed using `new` and `delete`.

* **Uses:**

  * Dynamic memory allocation
  * Objects that need lifespan beyond their scope
  * Data structures needing flexibility

* **Recommendation:**
  Prefer smart pointers (`std::unique_ptr`, `std::shared_ptr`) to manage resources safely.

---

## 10. RAII (Resource Acquisition Is Initialization)

RAII ensures resources (files, memory, etc.) are acquired when an object is initialized and released when the object goes out of scope.

**Example:**

```cpp
{
  std::ofstream output("log.txt"); // automatically opened
  output << "Logging info";
} // output file closed automatically here
```

* **Benefit:**
  Automatic resource management, ensuring exception-safe and clean code.

---
