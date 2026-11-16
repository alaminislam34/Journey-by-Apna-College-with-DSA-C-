# Bitwise Operators in C++: The Complete Beginner to DSA Guide

Welcome to the **Bitwise Operators** guide! This guide explains bitwise operators in **simple, easy-to-understand English** with step-by-step binary calculations, visual diagrams, and interview-ready shortcut tricks.

---

## Table of Contents

1. [What are Bits and Bitwise Operators?](#1-what-are-bits-and-bitwise-operators)
2. [The 6 Bitwise Operators at a Glance](#2-the-6-bitwise-operators-at-a-glance)
3. [Deep Dive into Each Operator](#3-deep-dive-into-each-operator)
   - [3.1 Bitwise AND (&)](#31-bitwise-and-)
   - [3.2 Bitwise OR (|)](#32-bitwise-or-)
   - [3.3 Bitwise XOR (^)](#33-bitwise-xor-)
   - [3.4 Bitwise NOT (~)](#34-bitwise-not-)
4. [1's Complement and 2's Complement](#4-1s-complement-and-2s-complement)
   - [What is 1's Complement?](#what-is-1s-complement)
   - [What is 2's Complement?](#what-is-2s-complement)
   - [Why Computers Use 2's Complement](#why-computers-use-2s-complement)
   - [Why does `~5` equal `-6` in C++?](#why-does-5-equal--6-in-c)
5. [Bitwise Shift Operators](#5-bitwise-shift-operators)
   - [5.1 Left Shift Operator (<<)](#51-left-shift-operator-)
   - [5.2 Right Shift Operator (>>)](#52-right-shift-operator-)
6. [Essential Bit Manipulation Tricks & Shortcuts](#6-essential-bit-manipulation-tricks--shortcuts)
   - [Trick 1: Check Odd or Even](#trick-1-check-odd-or-even)
   - [Trick 2: Check if the i-th Bit is Set](#trick-2-check-if-the-i-th-bit-is-set)
   - [Trick 3: Set the i-th Bit (Make it 1)](#trick-3-set-the-i-th-bit-make-it-1)
   - [Trick 4: Clear the i-th Bit (Make it 0)](#trick-4-clear-the-i-th-bit-make-it-0)
   - [Trick 5: Toggle the i-th Bit (Flip it)](#trick-5-toggle-the-i-th-bit-flip-it)
   - [Trick 6: Check if a Number is a Power of 2](#trick-6-check-if-a-number-is-a-power-of-2)
   - [Trick 7: Clear the Lowest Set Bit](#trick-7-clear-the-lowest-set-bit)
   - [Trick 8: Count Set Bits (Brian Kernighan's Algorithm)](#trick-8-count-set-bits-brian-kernighans-algorithm)
   - [Trick 9: Swap Two Numbers Without a Temp Variable](#trick-9-swap-two-numbers-without-a-temp-variable)
   - [Trick 10: Find the Unique (Single) Number](#trick-10-find-the-unique-single-number)
7. [Important Operator Precedence Warning](#7-important-operator-precedence-warning)
8. [Quick Shortcut Cheat Sheet](#8-quick-shortcut-cheat-sheet)

---

## 1. What are Bits and Bitwise Operators?

### What is a Bit?
Inside a computer, everything is stored in binary: **0** or **1**.
- `0` means **OFF** (false).
- `1` means **ON** (true).

For example, the number `5` in decimal is represented as `101` in binary:
```
Decimal 5 = (1 * 2^2) + (0 * 2^1) + (1 * 2^0) = 4 + 0 + 1 = 101 in binary
```

### What are Bitwise Operators?
Normal operators (like `+`, `-`, `*`) work on the whole number.
**Bitwise operators work directly on each individual bit (0 and 1)** of integers.

Because the computer's CPU processes bits natively in hardware, bitwise operations are **extremely fast** ($O(1)$ time) and consume zero extra memory.

---

## 2. The 6 Bitwise Operators at a Glance

| Symbol | Name | What it does | Example (`a = 5`, `b = 6`) | Result |
| :---: | :---: | :--- | :--- | :---: |
| `&` | **Bitwise AND** | Result bit is `1` only if **both** bits are `1` | `5 & 6` | `4` |
| `\|` | **Bitwise OR** | Result bit is `1` if **at least one** bit is `1` | `5 \| 6` | `7` |
| `^` | **Bitwise XOR** | Result bit is `1` if bits are **different** | `5 ^ 6` | `3` |
| `~` | **Bitwise NOT** | **Inverts** all bits (`0` becomes `1`, `1` becomes `0`) | `~5` | `-6` |
| `<<` | **Left Shift** | Shifts bits to the **left**, fills right side with `0` | `5 << 1` | `10` |
| `>>` | **Right Shift** | Shifts bits to the **right**, removes rightmost bits | `5 >> 1` | `2` |

---

## 3. Deep Dive into Each Operator

Let's use two numbers for our step-by-step calculations:
- `a = 5` $\rightarrow$ in 4-bit binary: `0101`
- `b = 6` $\rightarrow$ in 4-bit binary: `0110`

---

### 3.1 Bitwise AND (`&`)

#### Truth Table:
| Bit A | Bit B | A & B |
| :---: | :---: | :---: |
| 0 | 0 | **0** |
| 0 | 1 | **0** |
| 1 | 0 | **0** |
| 1 | 1 | **1** |

> 💡 **Rule:** Both bits must be `1` to get `1`. Otherwise, the result is `0`.

#### Step-by-Step Calculation: `5 & 6`
```text
    5  =  0 1 0 1
    6  =  0 1 1 0
  ----------------
5 & 6  =  0 1 0 0   --> (0*8 + 1*4 + 0*2 + 0*1) = 4
```

#### C++ Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 6;
    cout << (a & b) << endl; // Output: 4
    return 0;
}
```

---

### 3.2 Bitwise OR (`|`)

#### Truth Table:
| Bit A | Bit B | A \| B |
| :---: | :---: | :---: |
| 0 | 0 | **0** |
| 0 | 1 | **1** |
| 1 | 0 | **1** |
| 1 | 1 | **1** |

> 💡 **Rule:** If either bit is `1`, the result is `1`. It only gives `0` if both bits are `0`.

#### Step-by-Step Calculation: `5 | 6`
```text
    5  =  0 1 0 1
    6  =  0 1 1 0
  ----------------
5 | 6  =  0 1 1 1   --> (0*8 + 1*4 + 1*2 + 1*1) = 7
```

#### C++ Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 6;
    cout << (a | b) << endl; // Output: 7
    return 0;
}
```

---

### 3.3 Bitwise XOR (`^`)

**XOR** stands for **eXclusive OR**.

#### Truth Table:
| Bit A | Bit B | A ^ B |
| :---: | :---: | :---: |
| 0 | 0 | **0** (Same) |
| 0 | 1 | **1** (Different) |
| 1 | 0 | **1** (Different) |
| 1 | 1 | **0** (Same) |

> 💡 **Rule:**
> - If bits are **different** $\rightarrow$ `1`
> - If bits are **the same** $\rightarrow$ `0`

#### Golden Properties of XOR (Very important for DSA!):
1. `x ^ 0 = x` (XOR with 0 leaves the number unchanged)
2. `x ^ x = 0` (XOR with itself cancels out to 0)
3. `x ^ y = y ^ x` (Commutative)
4. `(x ^ y) ^ z = x ^ (y ^ z)` (Associative)

#### Step-by-Step Calculation: `5 ^ 6`
```text
    5  =  0 1 0 1
    6  =  0 1 1 0
  ----------------
5 ^ 6  =  0 0 1 1   --> (0*8 + 0*4 + 1*2 + 1*1) = 3
```

#### C++ Code:
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 6;
    cout << (a ^ b) << endl; // Output: 3
    return 0;
}
```

---

### 3.4 Bitwise NOT (`~`)

The `~` operator is a **unary operator** (it works on only one number).
It inverts all bits: every `0` becomes `1`, and every `1` becomes `0`.

#### Truth Table:
| Bit A | ~A |
| :---: | :---: |
| 0 | **1** |
| 1 | **0** |

To understand how `~` works on real numbers in C++, we must understand **1's Complement** and **2's Complement**.

---

## 4. 1's Complement and 2's Complement

### What is 1's Complement?
To find the 1's complement of a binary number, simply **flip all bits**:
- `0` becomes `1`
- `1` becomes `0`

**Example:**
- Original: `1 0 1 1 0 0`
- 1's Complement: `0 1 0 0 1 1`

---

### What is 2's Complement?
2's complement is how modern computers represent **negative numbers**.

$$\text{2's Complement} = (\text{1's Complement}) + 1$$

**Example: Find 2's complement of `5` (using 8 bits):**
1. Write 5 in 8-bit binary:
   `0000 0101`
2. Take 1's complement (flip all bits):
   `1111 1010`
3. Add 1:
   ```text
       1111 1010
     +         1
     -----------
       1111 1011  <-- This represents -5 in 2's complement!
   ```

---

### Why Computers Use 2's Complement
1. **Single zero:** Older systems had $+0$ and $-0$, which was confusing and wasted memory. 2's complement has only one zero (`0000 0000`).
2. **Simple hardware addition:** The CPU uses the exact same addition circuit for both positive and negative numbers: `A - B = A + (2's complement of B)`.
3. **Sign Bit:** The Most Significant Bit (MSB, leftmost bit) indicates the sign:
   - If MSB is `0` $\rightarrow$ Positive number
   - If MSB is `1` $\rightarrow$ Negative number

---

### Why does `~5` equal `-6` in C++?

In C++, integers are typically 32-bit signed integers stored in 2's complement form.

Let's trace `int a = 5; cout << ~a;`:

1. Represent `5` in 32-bit binary:
   ```text
   00000000 00000000 00000000 00000101
   ```
2. Apply `~` (flip every bit):
   ```text
   11111111 11111111 11111111 11111010
   ```
3. Notice the leftmost bit (MSB) is now `1`. This means the computer sees this as a **negative number**.
4. How does the computer read the value of a negative number? It takes the **2's complement** of that binary to find its magnitude:
   - Invert bits back: `00000000 00000000 00000000 00000101` (5)
   - Add 1: `5 + 1 = 6`
   - Attach the negative sign: `-6`

#### Universal Formula for Bitwise NOT:
$$\sim x = -(x + 1)$$

- `~5`  $= -(5 + 1) = -6$
- `~0`  $= -(0 + 1) = -1$
- `~(-6)` $= -(-6 + 1) = 5$

---

## 5. Bitwise Shift Operators

Shift operators shift the binary bits to the left or to the right by a specified number of positions.

---

### 5.1 Left Shift Operator (`<<`)

`a << b` shifts the bits of `a` to the **left** by `b` positions.
- Bits on the left are discarded.
- Vacant positions on the right are filled with **0**.

#### Visual Example: `5 << 2`
Let's represent `5` in 8 bits: `0000 0101`

```text
Original:      0 0 0 0 0 1 0 1   (5)
Shift left 1:  0 0 0 0 1 0 1 0   (10)
Shift left 2:  0 0 0 1 0 1 0 0   (20)
                         ^ ^
             (two 0s added on the right)
```
Result: `20`

#### Mathematical Formula:
$$a \ll b = a \times 2^b$$

- `5 << 1` = $5 \times 2^1 = 10$
- `5 << 2` = $5 \times 2^2 = 20$
- `5 << 3` = $5 \times 2^3 = 40$
- `1 << n` = $2^n$ *(Super useful shortcut to get powers of 2!)*

---

### 5.2 Right Shift Operator (`>>`)

`a >> b` shifts the bits of `a` to the **right** by `b` positions.
- Bits shifted off the right side are discarded.
- For positive numbers, vacant positions on the left are filled with **0**.

#### Visual Example: `20 >> 2`
Let's represent `20` in 8 bits: `0001 0100`

```text
Original:       0 0 0 1 0 1 0 0   (20)
Shift right 1:  0 0 0 0 1 0 1 0   (10)
Shift right 2:  0 0 0 0 0 1 0 1   (5)
                ^ ^
         (zeros added on left)
```
Result: `5`

Another example with odd number division: `13 >> 2`
```text
13 in binary:   0000 1101
Shift right 2:  0000 0011  (Value = 3)
```

#### Mathematical Formula:
$$a \gg b = \lfloor \frac{a}{2^b} \rfloor$$

- `20 >> 1` = $\lfloor 20 / 2^1 \rfloor = 10$
- `20 >> 2` = $\lfloor 20 / 2^2 \rfloor = 5$
- `13 >> 2` = $\lfloor 13 / 4 \rfloor = 3$

> ⚠️ **Note on Negative Numbers (Arithmetic vs Logical Shift):**
> In C++, right-shifting a negative signed integer typically preserves the sign by copying the sign bit `1` into the left positions (Arithmetic Shift).

---

## 6. Essential Bit Manipulation Tricks & Shortcuts

These are the most common bitwise tricks asked in coding interviews and competitive programming.

---

### Trick 1: Check Odd or Even

**Concept:**
- In binary, an **even** number always ends in `0` (e.g., $4 = 100_2$, $6 = 110_2$).
- In binary, an **odd** number always ends in `1` (e.g., $5 = 101_2$, $7 = 111_2$).

If we perform `n & 1`:
- If `n & 1 == 1` $\rightarrow$ Number is **ODD**
- If `n & 1 == 0` $\rightarrow$ Number is **EVEN**

```cpp
if (n & 1) {
    cout << "Odd\n";
} else {
    cout << "Even\n";
}
```
> ⚡ `n & 1` is faster than `n % 2 != 0`.

---

### Trick 2: Check if the $i$-th Bit is Set

*(Bits are indexed starting from 0, from right to left).*

```text
Bit index:   ... 4 3 2 1 0
Number 13:       0 1 1 0 1
```

#### Method 1: Using Left Shift Mask
Create a mask `(1 << i)` where only the $i$-th bit is `1`, then use `&`:
```cpp
bool isSet = (n & (1 << i)) != 0;
```

#### Method 2: Using Right Shift
Shift the $i$-th bit to position 0, then check with `& 1`:
```cpp
bool isSet = ((n >> i) & 1) == 1;
```

**Trace for `n = 13` (`1101`), checking $i = 2$:**
- `1 << 2` is `0100` (4)
- `1101 & 0100 = 0100 != 0` $\rightarrow$ True! The 2nd bit is set.

---

### Trick 3: Set the $i$-th Bit (Make it 1)

Use Bitwise OR (`|`) with a mask `(1 << i)`.
Because `x | 1` is always `1`, and `x | 0` is `x`, only the $i$-th bit becomes `1`:

```cpp
n = n | (1 << i);
```

**Trace for `n = 9` (`1001`), set $i = 1$:**
```text
    9  =  1 0 0 1
1 << 1 =  0 0 1 0
-----------------
Result =  1 0 1 1  --> 11
```

---

### Trick 4: Clear the $i$-th Bit (Make it 0)

Use Bitwise AND (`&`) with inverted mask `~(1 << i)`:

```cpp
n = n & ~(1 << i);
```

**Trace for `n = 13` (`1101`), clear $i = 2$:**
```text
  1 << 2  =  0 1 0 0
~(1 << 2) =  1 0 1 1
       n  =  1 1 0 1
--------------------
  Result  =  1 0 0 1  --> 9
```

---

### Trick 5: Toggle the $i$-th Bit (Flip it)

If it is `0`, make it `1`. If it is `1`, make it `0`.
Use Bitwise XOR (`^`) with `(1 << i)`:

```cpp
n = n ^ (1 << i);
```

**Trace for `n = 9` (`1001`), toggle $i = 1$:**
```text
    9  =  1 0 0 1
1 << 1 =  0 0 1 0
-----------------
Result =  1 0 1 1  --> 11 (bit 1 flipped from 0 to 1)
```

---

### Trick 6: Check if a Number is a Power of 2

A power of 2 has **exactly one bit set** to `1`:
- $2 = 0010_2$
- $4 = 0100_2$
- $8 = 1000_2$

Notice what happens when you subtract 1:
- $8 = 1000_2$
- $8 - 1 = 7 = 0111_2$

If you perform `n & (n - 1)`:
```text
  8     = 1 0 0 0
  7     = 0 1 1 1
-----------------
8 & 7   = 0 0 0 0  (Becomes 0!)
```

#### Code:
```cpp
bool isPowerOfTwo = (n > 0) && ((n & (n - 1)) == 0);
```

---

### Trick 7: Clear the Lowest Set Bit

The expression `n & (n - 1)` turns the rightmost `1` bit into `0`.

**Trace for `n = 12` (`1100`):**
```text
     12  =  1 1 0 0
     11  =  1 0 1 1
-------------------
12 & 11  =  1 0 0 0  --> Rightmost '1' at index 2 turned into 0!
```

---

### Trick 8: Count Set Bits (Brian Kernighan's Algorithm)

Counting how many `1`s are in a number's binary form:

```cpp
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1); // Clears the lowest set bit each loop
        count++;
    }
    return count;
}
```
- **Time Complexity:** $O(\text{number of set bits})$, much faster than checking all 32 bits!

#### C++ Built-in function:
```cpp
int count = __builtin_popcount(n); // For regular integers
int countLL = __builtin_popcountll(n); // For long long
```

---

### Trick 9: Swap Two Numbers Without a Temp Variable

Using the self-canceling property of XOR:

```cpp
int a = 5, b = 7;

a = a ^ b;
b = a ^ b; // b becomes (a ^ b) ^ b = a
a = a ^ b; // a becomes (a ^ b) ^ a = b

// Now a = 7, b = 5!
```

---

### Trick 10: Find the Unique (Single) Number

**Problem:** You are given an array where every element appears twice, except for one element which appears once. Find that single element.

**Example:** `arr = [4, 1, 2, 1, 2]`

Because:
- $x \oplus x = 0$
- $x \oplus 0 = x$

If we XOR all elements together, all pairs cancel each other out, leaving only the unique number:

```cpp
int findSingle(vector<int>& nums) {
    int ans = 0;
    for (int num : nums) {
        ans ^= num;
    }
    return ans; // Returns 4
}
```

---

## 7. Important Operator Precedence Warning

In C++, comparison operators (like `==`, `!=`, `<`, `>`) have **HIGHER precedence** than bitwise operators (`&`, `|`, `^`).

### The Classic Bug:
```cpp
// ❌ WRONG!
if (n & 1 == 0) // Evaluated as: n & (1 == 0) => n & 0 => always 0 (false)!
```

### The Correct Way:
Always use parentheses around bitwise operations:
```cpp
// ✅ CORRECT!
if ((n & 1) == 0) // Evaluated properly!
```

---

## 8. Quick Shortcut Cheat Sheet

| Task | Formula / Code |
| :--- | :--- |
| **Check Odd / Even** | `(n & 1) != 0` (Odd if true) |
| **Multiply by $2^k$** | `n << k` |
| **Divide by $2^k$** | `n >> k` |
| **Check if $i$-th bit is set** | `((n >> i) & 1) == 1` or `(n & (1 << i)) != 0` |
| **Set $i$-th bit to 1** | `n = n \| (1 << i)` |
| **Clear $i$-th bit to 0** | `n = n & ~(1 << i)` |
| **Toggle $i$-th bit** | `n = n ^ (1 << i)` |
| **Check Power of 2** | `(n > 0) && ((n & (n - 1)) == 0)` |
| **Clear lowest set bit** | `n = n & (n - 1)` |
| **Isolate lowest set bit** | `n & (-n)` |
| **Count set bits** | `__builtin_popcount(n)` |
| **Formula for `~x`** | `~x = -(x + 1)` |
| **Swap `a` and `b`** | `a ^= b; b ^= a; a ^= b;` |

---

> Happy Coding! Practice these patterns in your DSA journey to write cleaner, faster, and more optimal C++ code!

