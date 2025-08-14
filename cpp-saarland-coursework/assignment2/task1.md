### Differences Between `const` and `static` in C++

The `const` keyword is all about **safety and promises**:  
When we declare something as `const`, we are telling the compiler (and other programmers) that this value or function **won’t change**.  
For example, a `const int` is a number that, once set, is fixed — no one can modify it accidentally or intentionally.  
This is useful when you want to **protect important values** or **signal intent clearly** in your code.

On the other hand, `static` focuses on **how long something lives** and **where it belongs**:  
- A `static` variable inside a function **keeps its value between calls**, like a hidden memory that remembers what happened last time.
- In a class, a `static` member belongs to **the class itself**, not to any specific object, meaning it’s **shared by all instances**.
- At the file level, `static` **limits visibility to the current file only**, like putting up a wall around it so other files can’t see it.

In short:  
- **`const`** → guarantees immutability.  
- **`static`** → controls lifetime, scope, and sharing.
---
### Why Should You Distinguish Between Functions That Modify Objects and Those That Do Not?

In C++, it’s important to distinguish between functions that **modify** an object and those that **do not** because it’s about **clarity, safety, and good design**.

When you have a function that only reads the state of an object (for example, getting the balance of a bank account), you want to tell both the compiler and other programmers,  
> **“Don’t worry, there is nothing changing here.”**

and we do this by marking the function as `const`.

Why does this matter?

- **Prevents accidental changes:**  
  The compiler will stop you if you try to modify something inside a `const` function.

- **Allows calling on `const` objects:**  
  If you have an object marked as read-only, you can still safely call these non-modifying functions.

- **Improves code clarity:**  
  Anyone reading class can easily tell which methods are safe for reading and which ones are meant to update things.

In short, distinguishing between modifying and non-modifying functions isn’t just a C++ technicality; it’s a way to write safer, clearer, and more robust code.


### What is the Concept and Effect of Inline Functions? When Would You Prefer Inline Functions Over Function Calls?

---
In C++, an `inline` function is a special request to the compiler to **replace a function call with the actual function code itself**.  
Instead of making the program jump to another location to run the function, the compiler directly **injects the function’s body** into the spot where it’s called.

---

#### **Effect of Inline Functions**

- **Reduces function call overhead:**  
  There’s no need to push arguments to the stack, jump to a new address, and return.

- **Potential speed-up:**  
  Especially helpful for small, frequently called functions like math operations or simple getters.

- **Allows further compiler optimizations:**  
  The compiler can sometimes apply additional optimizations when code is directly visible.

---

#### **Potential Drawbacks**

- **Increases binary size (code bloat):**  
  Because the function body is duplicated at each call site.

- **May hurt performance overall:**  
  Bigger binaries can reduce instruction cache efficiency.

- **Compiler may ignore the request:**  
  Modern compilers often decide on their own whether to inline, regardless of the `inline` keyword.

---

#### **When to Prefer Inline Functions**

we should consider using inline functions when:
- The function is **small** and **called frequently**.
- we want to **avoid the cost of function calls**, especially in tight loops.
- The function is simple enough that duplicating it won’t noticeably increase binary size.

we **should not** inline:
- Large, complex functions.
- Functions defined only in `.cpp` files (inlining works best in header files).

---

In short, inline functions are a tool to optimize small, critical parts of your code — but they should be used carefully, balancing performance gains against code size.

---
### What is a Destructor and When Is It Called? What Is the Typical Consequence of Its Usage?

In C++, a **destructor** is a special function inside a class that is used to **clean up resources** when an object’s lifetime ends.  
It has:
- **No arguments**.
- **No return type**.
- The name `~ClassName()` (a tilde followed by the class name).

---

#### **When Is It Called?**

A destructor is called **automatically**:
- When a local object goes out of scope.
- When we `delete` a dynamically allocated object.
- When the program shuts down and cleans up global/static objects.

we **don’t need to call it yourself** — the compiler ensures it runs at the right moment.

---

#### **Typical Consequence of Destructor Usage**

The destructor’s main job is to:
- **Free up resources** (like memory, file handles, network connections).
- Prevent **memory leaks** or resource leaks.
- Leave the system in a **clean, stable state** after the object is gone.

Proper destructor use is essential in managing resource-heavy objects and keeping the program efficient and bug-free.

---

### In Which Context Are Virtual Functions Used?

In C++, **virtual functions** are used in the context of **polymorphism**.  
They allow a derived (child) class to **override** a method from its base (parent) class, so that when we call the method **through a base class pointer or reference**, the derived class’s version is executed.

---

#### **Why Use Virtual Functions?**

- To enable **runtime decision-making** on which function to call.
- To design **flexible base classes** that can be extended by child classes.
- To support **polymorphism**, where different derived objects can behave differently even when treated as the same base type.

In short, virtual functions are key when you want to write code that works with **general types** but behaves correctly for **specific derived classes**.

---

### When Would we Make a Virtual Member Function Pure?

we would make a virtual member function **pure** when you want to define an **abstract base class** that cannot be instantiated on its own  
and where **all derived classes are required to provide their own implementation** of that function.

---

#### **Why Use a Pure Virtual Function?**

- To enforce a **contract**: every subclass **must** implement this function.
- To define an **interface** in the base class without giving any default behavior.
- To ensure the base class stays **abstract** (no objects can be created from it).

In short, we use pure virtual functions when you only care about **what** should be done, not **how** it’s done — leaving the “how” to the derived classes.

---
### What Are Pitfalls of Multiple Inheritance?

Multiple inheritance in C++ allows a class to inherit from **more than one base class**,  
but it comes with several potential pitfalls:

---

#### **Main Pitfalls**

- **Diamond problem:**  
  When two base classes share a common ancestor, the derived class may inherit **multiple copies** of the shared base, leading to ambiguity and duplication.

- **Ambiguity:**  
  If both base classes define the same method or member, the compiler won’t know which one the derived class should use unless explicitly specified.

- **Increased complexity:**  
  Managing and maintaining a class hierarchy with multiple inheritance can become harder, making the code more error-prone.

---

In short, while powerful, multiple inheritance should be used carefully due to these risks.
