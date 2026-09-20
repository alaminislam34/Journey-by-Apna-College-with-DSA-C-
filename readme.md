# Arrays, Linear Search & Binary Search in C++

A simple, step-by-step guide for beginners: how arrays work, and how we search for a value inside them — first with **Linear Search**, then with **Binary Search**.

---

## Table of Contents

1. [What is an Array?](#1-what-is-an-array)
2. [How to Make and Use an Array in C++](#2-how-to-make-and-use-an-array-in-c)
3. [Linear Search](#3-linear-search)
4. [Binary Search](#4-binary-search)
5. [Which One Should You Use?](#5-which-one-should-you-use)
6. [Time Complexity Summary](#6-time-complexity-summary)

---

## 1. What is an Array?

An **array** is a way to store **many values of the same type in one place**, one after another, in memory.

### Why do we need arrays?

Imagine you want to store the marks of 10 students.

**Without an array**, you need 10 different variables:

```cpp
int s1 = 70;
int s2 = 85;
int s3 = 92;
// ... 7 more variables
```

**With an array**, you need only one:

```cpp
int marks[10];   // one variable that holds 10 numbers
```

### How does it look in memory?

An array is stored as **one continuous block of memory**. Each box is called an **element**, and each element has a number called an **index**.

```
Array:  { 10, 20, 30, 40, 50 }

Memory boxes:
┌────────┬────────┬────────┬────────┬────────┐
│  10    │  20    │  30    │  40    │  50    │
└────────┴────────┴────────┴────────┴────────┘
  index 0    index 1   index 2   index 3   index 4
```

### Important rules

- Index starts from **0**, not 1.
- An array with `n` elements has valid indexes from `0` to `n-1`.
- The **last index** is always `size - 1`.
- Accessing an element is **instant** — this is called **O(1) access**.
  Example: `arr[3]` gives you the 4th value directly, no counting needed.

> 💡 **Easy memory trick:** Think of an array like a row of lockers.
> Each locker has a number (the index), and you can open any locker
> immediately by its number — locker 0, locker 1, locker 50...

---

## 2. How to Make and Use an Array in C++

### 2.1 Creating an array

```cpp
int arr[] = {1, 2, 3, 4, 5};   // array of 5 integers
```

### 2.2 Finding the size of an array

```cpp
int n = sizeof(arr) / sizeof(int);   // n = 5
```

How it works:
- `sizeof(arr)` → total size in bytes (5 integers = 20 bytes)
- `sizeof(int)` → size of one integer (4 bytes)
- `20 / 4 = 5` → number of elements ✅

### 2.3 Reading and changing elements

```cpp
int value = arr[2];    // read  the element at index 2  → value = 3
arr[2] = 99;           // change the element at index 2  → arr[2] = 99
```

### 2.4 Printing the whole array

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";   // prints: 1 2 3 4 5
    }
    cout << endl;

    return 0;
}
```

---

## 3. Linear Search

### 3.1 What is it?

**Linear search** means: *check every element one by one, from left to right, until you find the value (the "key") or finish the array.*

It works on **any array** — sorted or not.

### 3.2 Step-by-step example

Array: `{ 10, 20, 30, 40, 50 }`
We want to find **key = 40**.

| Step | Index checked | Value | Match? |
|------|--------------|-------|--------|
| 1    | arr[0]       | 10    | ❌ no, move on |
| 2    | arr[1]       | 20    | ❌ no, move on |
| 3    | arr[2]       | 30    | ❌ no, move on |
| 4    | arr[3]       | 40    | ✅ YES! found at index 3 |

We stop and return **3**.

What if key = 99 (not in array)?
We check all 5 elements, find nothing, and return **-1** (meaning "not found").

### 3.3 Pseudocode

```
FUNCTION linearSearch(arr, n, key):
    FOR i FROM 0 TO n-1:
        IF arr[i] == key:
            RETURN i            // found it, return the index
    RETURN -1                   // finished loop, key was not there
```

### 3.4 C++ code

```cpp
#include <iostream>
using namespace std;

int linearSearch(int *arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;           // return index where key is found
        }
    }
    return -1;                  // key not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(int);

    int result = linearSearch(arr, n, 4);

    if (result == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index: " << result << endl;  // prints 3

    return 0;
}
```

### 3.5 Worst case

If the key is at the **last position** (or not there at all), we check every element:
- We do **n** comparisons → this is called **O(n)** time.
- For 1 million elements, that means up to 1 million checks. Slow!

> 💡 **Easy memory trick:** Linear search is like looking for a name in a
> random stack of papers — you must flip through them one by one.

---

## 4. Binary Search

### 4.1 What is it?

**Binary search** is a *much faster* way to search, but it has **one condition**:

> ⚠️ **The array MUST be sorted (in increasing order).**

It works by **cutting the search area in half every time** — like a game of "higher or lower".

### 4.2 Step-by-step example (this is the "higher or lower" game)

Array (sorted): `{ 2, 5, 8, 12, 16, 23, 38, 45, 56, 72 }`
We want to find **key = 23**.

---

**Round 1:**
```
low = 0, high = 9
mid = (0 + 9) / 2 = 4
arr[4] = 16

Is 16 == 23?  NO
Is 23 > 16?   YES → key is on the RIGHT side
So discard everything left of mid → low = mid + 1 = 5
```
```
[ 2,  5,  8, 12, 16, |  23, 38, 45, 56, 72 ]
  discarded ✂          ← search here →
```

---

**Round 2:**
```
low = 5, high = 9
mid = (5 + 9) / 2 = 7
arr[7] = 45

Is 45 == 23?  NO
Is 23 < 45?   YES → key is on the LEFT side
So discard everything right of mid → high = mid - 1 = 6
```
```
[  23, 38, |  45, 56, 72 ]
  ← search here →  discarded ✂
```

---

**Round 3:**
```
low = 5, high = 6
mid = (5 + 6) / 2 = 5
arr[5] = 23

Is 23 == 23?  YES ✅ FOUND IT! Return index 5
```

We found 23 in just **3 rounds**. With linear search it would have taken **6 checks**.
For 1 million elements: binary search needs only about **20 rounds** vs 1 million checks! 🚀

### 4.3 Pseudocode

```
FUNCTION binarySearch(arr, n, key):
    low  = 0
    high = n - 1

    WHILE low <= high:
        mid = low + (high - low) / 2        // find the middle

        IF arr[mid] == key:
            RETURN mid                      // found it!

        ELSE IF key > arr[mid]:
            low = mid + 1                   // key is in the right half
        ELSE:
            high = mid - 1                  // key is in the left half

    RETURN -1                               // low crossed high → not found
```

### 4.4 C++ code

```cpp
#include <iostream>
using namespace std;

int binarySearch(int *arr, int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;   // middle index (safe from overflow)

        if (arr[mid] == key) {
            return mid;                     // key found, return index
        }
        else if (key > arr[mid]) {
            low = mid + 1;                  // search the right half
        }
        else {
            high = mid - 1;                 // search the left half
        }
    }

    return -1;                              // key not found
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};   // sorted!
    int n = sizeof(arr) / sizeof(int);

    int result = binarySearch(arr, n, 23);

    if (result == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index: " << result << endl;  // prints 5

    return 0;
}
```

### 4.5 Why `low + (high - low) / 2` instead of `(low + high) / 2`?

Both work for small arrays. But with very big arrays, `low + high` can become
larger than the biggest number `int` can hold (this is called **integer overflow**).
Writing `low + (high - low) / 2` gives the same answer but **never overflows**.

### 4.6 Why must the array be sorted?

Binary search decides "go left" or "go right" by comparing the middle element.
That decision is only correct if the array is sorted. On an unsorted array,
the value could be anywhere — so we'd have no choice but to check everything
(one by one), which is just linear search again.

> 💡 **Easy memory trick:** Binary search is like finding a word in a dictionary.
> You open it in the middle. "A" comes before the middle word? Go to the left
> half. After? Go to the right half. Repeat — you find the word super fast.

---

## 5. Which One Should You Use?

| Situation | Use this | Why |
|-----------|----------|-----|
| Array is **not sorted** | Linear Search | Binary search needs sorted data |
| Array is **sorted**, any size | Binary Search | Much faster |
| Array is **small** (a few elements) | Either — doesn't matter | Both are fast enough |
| Array is **huge** (millions of elements) | Binary Search | 20 checks vs 1,000,000 checks |
| You search **one time only** in a small list | Linear Search | Simpler code |
| You search **many times** in the same sorted data | Binary Search | Saves tons of time each time |

---

## 6. Time Complexity Summary

| Algorithm | Worst case | Example (1,000,000 elements) |
|-----------|-----------|------------------------------|
| Linear Search | **O(n)** — checks every element | up to 1,000,000 comparisons |
| Binary Search | **O(log n)** — halves the list each time | only ~20 comparisons |

### What does O(n) vs O(log n) really mean?

- **O(n):** time grows *with* the size. Double the data → double the time.
- **O(log n):** time grows *slowly*. Double the data → only 1 extra step.

| Elements | Linear (worst case) | Binary (worst case) |
|----------|--------------------:|--------------------:|
| 10 | 10 | 4 |
| 100 | 100 | 7 |
| 1,000 | 1,000 | 10 |
| 1,000,000 | 1,000,000 | 20 |
| 1,000,000,000 | 1,000,000,000 | 30 |

---

## Quick Cheat Sheet

```cpp
// 1. MAKE an array
int arr[] = {10, 20, 30, 40, 50};

// 2. SIZE of array
int n = sizeof(arr) / sizeof(int);        // n = 5

// 3. READ / WRITE element
int x = arr[2];                           // x = 30
arr[2] = 99;                              // arr[2] becomes 99

// 4. LINEAR SEARCH  (any array)
//    → check from index 0 to n-1 one by one
//    → worst case O(n)

// 5. BINARY SEARCH  (sorted array only!)
//    → find mid, compare, cut half, repeat
//    → worst case O(log n)
```

### One-line summary

> **Linear search** = check every box one by one (slow but works always).
> **Binary search** = cut the pile in half every time (very fast, but the pile must be sorted).

---

*Practice tip: type both C++ programs above into your compiler, change the
`key` value, and watch which indexes get checked. Trying it yourself is the
fastest way to make it stick!* 🚀
