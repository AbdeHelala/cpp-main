# cpp-main

C++ playground repo containing:

* **Competitive Programming** — accepted Codeforces solutions (Assiut University “Newcomers” track).
* **Saarland Coursework** — C++ assignments (data structures, algorithms, templates, iterators, CMake).

---

## Repository structure

```
cpp-main/
├── competitive-programming-cpp/
│   ├── code-forces/                 # Assiut Newcomers solutions (by sheet/contest)
│   │   ├── Contest #1/
│   │   ├── Contest #2/
│   │   ├── Contest #3.1/
│   │   ├── Sheet #1 (Data type - Conditions)/
│   │   ├── Sheet #2 (Loops)/
│   │   ├── Sheet #3 (Arrays)/
│   │   ├── Sheet #4 (Strings)/
│   │   ├── Sheet #5 (Functions)/
│   │   └── Sheet #6 (Math - Geometry)/
│   ├── codeforces-cpp-solutions/    
│   └── cpp-problem-solving/         
└── cpp-saarland-coursework/
    ├── assignment0/                 # warm-up tests
    ├── assignment1/                 # IO, control flow, small algorithms
    ├── assignment2/                 # mini DataFrame + nodes (CMake project)
    ├── assignment3/                 # Matrix class + custom iterators
    └── assignment4/                 # Counting Bloom Filter, Munkres (Hungarian), utilities
```

---

## Quick start

### Compile & run a single solution (C++17)

```bash
# from inside any folder with a .cpp file
g++ -std=c++17 -O2 -pipe -static -s A_175248491.cpp -o A
./A < input.txt
```

> Some problems are in Python; run with `python file.py < input.txt>`.

### Build coursework (CMake)

```bash
# example: cpp-saarland-coursework/assignment2/code
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
./build/your_binary_name
```

**Toolchain**: GCC/Clang (C++17), or MSYS2/MinGW-w64 on Windows. Any recent Linux/WSL/Mac toolchain works.

---

## Competitive Programming (Codeforces)

* **Track**: Assiut University Training — Newcomers
  Group contests: [https://codeforces.com/group/MWSDmqGsZm/contests](https://codeforces.com/group/MWSDmqGsZm/contests)
  Master problem list (Google Sheet):
  [https://docs.google.com/spreadsheets/d/12XlGl2Nae1NXRDNet\_bGQ2HM2O3kq-9FS0Jm2pDwFyg/edit?gid=0#gid=0](https://docs.google.com/spreadsheets/d/12XlGl2Nae1NXRDNet_bGQ2HM2O3kq-9FS0Jm2pDwFyg/edit?gid=0#gid=0)

**Layout & naming**

* Solutions are grouped by **Sheet** / **Contest** (matching Codeforces).
* Filenames follow: `LETTER_SUBMISSIONID.ext`
  e.g., `A_175248491.cpp`, `B_267867984.py`.
* Only **accepted** submissions are stored (some problems have multiple accepted variants).

**Sheets covered so far**

* \#1 Data types & conditions
* \#2 Loops
* \#3 Arrays
* \#4 Strings
* \#5 Functions
* \#6 Math / Geometry
* Contests: **#1**, **#2**, **#3.1**

---

## Saarland C++ Coursework (highlights)

* **assignment0** – warm-up test files and harness.
* **assignment1** – small algorithms (I/O parsing, branching, loops), multiple tasks with separate `.cpp` files.
* **assignment2** – a minimal **DataFrame**-like structure (columns, types, simple nodes) with CMake.
* **assignment3** – a templated **Matrix** class and **custom iterators** (row/col/element), plus algorithms using them.
* **assignment4** – **Counting Bloom Filter** (hashing with `murmurhash`), **Munkres/Hungarian algorithm** for assignment, extra utilities.

Each assignment folder includes its own `code/` subfolder and `CMakeLists.txt` where applicable.

---

## Notes

* C++ standard: **C++17** across the repo.
* Use `-O2 -pipe -static -s` for Codeforces-style builds when possible.
* Inputs/outputs follow the original problem statements; see comments in files when present.

---

## Authors

* **Abdelsalam Helala** (abdelslam\_10 on Codeforces)

If you find an issue or want to suggest a cleaner solution for a problem, feel free to open a PR.
