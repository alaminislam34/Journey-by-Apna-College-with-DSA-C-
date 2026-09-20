# C++ Beginner to DSA: The Complete Step-by-Step Guide

A complete learning guide in **easy words**, with **easy examples** and **step-by-step explanation** for every topic:

1. C++ Boilerplate
2. Data Types
3. Variables
4. Operators
5. Conditional Statements
6. Loops
7. Pattern Printing
8. Functions
9. Binary Number System
10. Arrays
11. Linear Search
12. Binary Search

> 📌 **How to use this guide:** Read one topic fully, type every code example into a compiler yourself, change the numbers and see what changes. That is the fastest way to learn!

---

## Table of Contents

- [1. C++ Boilerplate](#1-c-boilerplate)
- [2. Data Types](#2-data-types)
- [3. Variables](#3-variables)
- [4. Operators](#4-operators)
- [5. Conditional Statements](#5-conditional-statements)
- [6. Loops](#6-loops)
- [7. Pattern Printing](#7-pattern-printing)
- [8. Functions](#8-functions)
- [9. Binary Number System](#9-binary-number-system)
- [10. Arrays](#10-arrays)
- [11. Linear Search](#11-linear-search)
- [12. Binary Search](#12-binary-search)
- [Quick Cheat Sheet](#quick-cheat-sheet)

---

## 1. C++ Boilerplate

### 1.1 What is a "boilerplate"?

A **boilerplate** is the basic skeleton of every C++ program. Every single C++ program you write starts with this structure. Think of it as the "frame of a house" — without it, nothing can stand.

### 1.2 The boilerplate

```cpp
#include <iostream>          // line 1: include input-output library
using namespace std;         // line 2: shortcut for std::

int main() {                 // line 3: main function STARTS
    // your code goes here
    return 0;                // line 5: tell the OS "program finished OK"
}                            // line 6: main function ENDS
```

### 1.3 What each line does (step by step)

**Line 1: `#include <iostream>`**
- `#include` is a preprocessor command. It means "paste the contents of this file into my program before compiling."
- `iostream` = **I**nput-**Output** STream. It gives us `cin` (read input) and `cout` (show output).
- Without this line, `cout` and `cin` do not exist → compile error.

**Line 2: `using namespace std;`**
- All the C++ standard stuff (like `cout`, `cin`) lives inside a "room" called `std` (short for standard).
- Normally you'd have to write `std::cout << "hi";`
- `using namespace std;` says "I will use the `std` room, so let me write `cout` directly."
- It is a shortcut. Beginners use it all the time — no problem.

**Line 3: `int main() {`**
- `main` is the special function where your program **always starts executing**.
- `int` in front means "main will give back a whole number (int) at the end."
- The `{` opens the body of main. Everything you do goes inside.

**Line 5: `return 0;`**
- Sends a message back to the operating system: "0 = everything went fine."
- By convention, non-zero means "something went wrong."

**Line 6: `}`**
- Closes main. Everything between `{` and `}` is the program.

### 1.4 Your very first program

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!" << endl;   // print text on screen
    return 0;
}
```

Output:
```
Hello World!
```

### 1.5 `cout`, `<<`, `endl` explained

- `cout` = "console out" — the tool that prints to the screen.
- `<<` = "send this to the left." Read it as "cout, here is your text." You can chain them: `cout << a << " + " << b << " = " << a+b;`
- `endl` = "end line" — moves the cursor to the next line (same job as `"\n"`).

### 1.6 How does a C++ program actually run? (2 steps)

```
Your code (.cpp file)
        │
        ▼
  ┌───────────┐      ┌───────────────┐
  │ COMPILE   │ ───► │ LINK          │ ───► executable file (a.out / .exe)
  │ (C++ →    │      │ (combine with │
  │  machine  │      │  libraries)   │
  │  code)    │      └───────────────┘
  └───────────┘
        │
        ▼
  Run the executable on your computer
```

- **Compile:** the compiler reads your C++ and translates it to machine language. If there is a mistake (like a missing `;`), it reports a **compile error** and stops.
- **Run:** you run the produced executable. If the logic is wrong (like dividing by zero), the problem happens at **runtime** instead.

> 💡 **Easy memory trick:** `#include` = "I need tools."
> `int main()` = "showtime — program starts here."
> `cout` = "speak." `cin` = "listen." `return 0` = "I'm done, all good."

---

## 2. Data Types

### 2.1 What is a data type?

A **data type** tells the computer **what kind of data** a variable holds, and **how much memory** to give it.

Why does the computer need to know?
- An integer `7` needs a box big enough for a number.
- The letter `A` needs a box big enough for a character.
- A decimal `3.14` needs a bigger box with room for the point.

If the computer guesses wrong, it stores garbage or cuts off part of your value.

### 2.2 The basic (built-in) data types in C++

| Type | What it stores | Example value | Size | Range / precision |
|------|---------------|---------------|------|-------------------|
| `int` | whole numbers (no point) | `42`, `-7` | 4 bytes | about -21 billion to +21 billion |
| `float` | decimal numbers (medium) | `3.14` | 4 bytes | ~6-7 accurate digits |
| `double` | decimal numbers (big) | `3.1415926535` | 8 bytes | ~15-16 accurate digits |
| `char` | single character | `'A'`, `'7'` | 1 byte | 1 character |
| `bool` | true or false | `true`, `false` | 1 byte | 2 values only |
| `long long` | very big whole numbers | `9000000000` | 8 bytes | much bigger than int |

### 2.3 `int` — whole numbers

```cpp
int age = 25;        // ✅ 25 is a whole number
int pi = 3.14;       // ⚠️ compiles, but 3.14 gets CUT to 3!
int x = 10;
int y = 3;
cout << x / y;       // prints 3  (not 3.333...)
```

**Two important traps with int:**

1. **Cutting off:** `int pi = 3.14;` stores `3`. The `.14` is lost forever.
2. **Integer division:** `7 / 2` = `3`, not `3.5`. When both numbers are `int`, the answer is `int`.
   If you want `3.5`, use `7 / 2.0` or `(double)7 / 2`.

### 2.4 `float` and `double` — decimal numbers

```cpp
float f = 3.14f;        // 'f' at the end = this is a float
double d = 3.14159265;  // double is the default for decimals

cout << f << endl;      // prints 3.14
cout << d << endl;      // prints 3.14159265
```

- `float` = smaller box, less precise (6-7 digits).
- `double` = bigger box, much more precise (15-16 digits).
- **Rule of thumb: use `double` for decimals.** Only use `float` if a problem specifically asks for it.

### 2.5 `char` — one character

```cpp
char grade = 'A';       // ⚠️ single quotes for char!
char digit  = '7';      // '7' is the CHARACTER seven, not the number 7
cout << grade << endl;  // prints A
```

- Use **single quotes** `'A'` for a single character.
- Use **double quotes** `"A"` for a string (more than one character, or a word).
- Fun fact: every character has a number behind it (its **ASCII code**): `'A' = 65`, `'0' = 48`, `'a' = 97`. That's why `char c = 65;` also prints `A`.

### 2.6 `bool` — true or false

```cpp
bool isPass = true;
bool isFail = false;
cout << isPass << endl;   // prints 1   (true shows as 1)
cout << isFail << endl;   // prints 0   (false shows as 0)
```

- A `bool` can hold only **two** values: `true` or `false`.
- C++ prints `true` as `1` and `false` as `0` by default.
- You will use `bool` a lot with conditions and loops.

### 2.7 `long long` — huge numbers

```cpp
int bad = 3000000000;           // ⚠️ 3 billion is BIGGER than int can hold!
long long big = 3000000000LL;   // ✅ fits in long long
cout << big << endl;
```

- `int` tops out at about **2.1 billion**. If your number is bigger (like a phone number or big DSA counts), use `long long`.

### 2.8 Data type conversion

**Implicit (automatic) conversion:**
C++ quietly converts a smaller type to a bigger type when safe:

```cpp
int a = 5;
double b = a;      // b becomes 5.0  (int → double, automatic, safe)
char c = 65;       // c becomes 'A'  (int → char)
```

**Explicit (manual) conversion — "casting":**
You force the conversion yourself:

```cpp
double pi = 3.14159;
int whole = (int)pi;    // whole = 3   ← decimal part is CUT OFF (not rounded!)
cout << whole << endl;

int x = 7, y = 2;
double result = (double)x / y;   // result = 3.5  ✅
cout << result << endl;
```

⚠️ **Casting cuts, it does not round:** `(int)3.9` → `3`, not `4`.

### 2.9 `sizeof` — asking the size

```cpp
cout << sizeof(int)      << endl;   // 4  (bytes)
cout << sizeof(double)   << endl;   // 8
cout << sizeof(char)     << endl;   // 1
cout << sizeof(long long)<< endl;   // 8
```

> 💡 **Easy memory trick:** Match the box to the content.
> Whole number → `int`. Bigger whole number → `long long`.
> Decimal → `double`. One letter → `char`. Yes/No → `bool`.

---

## 3. Variables

### 3.1 What is a variable?

A **variable** is a named box in memory that stores a value you can read and change later.

Think of it like a labeled storage box:

```
┌─────────┐
│  age    │   ← the name (label)
│   25    │   ← the value (what's inside)
└─────────┘
```

### 3.2 How to declare a variable

Syntax:

```cpp
dataType  variableName = value;
   ①            ②          ③
```

- ① what kind of data (int, double, char...)
- ② a name you choose
- ③ the starting value (optional)

```cpp
int age = 25;             // box for a whole number, starts with 25
double gpa = 3.8;         // box for a decimal, starts with 3.8
char grade = 'A';         // box for one character
bool isPass = true;       // box for true/false
```

### 3.3 Naming rules (what is allowed, what is not)

**✅ Allowed:**
```cpp
int myScore = 90;
int student_age = 20;     // underscore is fine
int age2 = 22;            // digits are OK in the name
int _count = 5;           // starting with _ is OK
```

**❌ Not allowed (compile error!):**
```cpp
2cool = 10;               // ❌ cannot START with a digit
int my-score = 5;         // ❌ no minus sign in names
int class = 10;           // ❌ "class" is a reserved word (C++ needs it)
int int = 5;              // ❌ "int" is a reserved word too
```

**Rules in short:**
1. Only letters, digits, and `_`.
2. Cannot start with a digit.
3. Cannot be a reserved word (`int`, `class`, `return`, `if`...).
4. Names are **case sensitive**: `age` and `Age` are two different variables.

### 3.4 Assignment and changing values

```cpp
int score = 50;     // create + set
score = 75;         // change it (reuse the same box)
score = score + 10; // now 85
int other = score;  // copy the value → other is 85 (a SEPARATE box!)
```

⚠️ `int other = score;` copies the **value**, not the box. Change `score` and `other` stays the same. They are two independent boxes that happened to start with the same number.

### 3.5 Multiple variables in one line

```cpp
int a = 1, b = 2, c = 3;    // three int boxes in one line (allowed)
```

### 3.6 Declaring without a value

```cpp
int n;          // box created, but its value is GARBAGE (random junk)
cout << n;      // ⚠️ prints some random number — risky!
n = 10;         // always set it before using it
```

> 💡 **Golden rule: always give a variable a value before reading it.**
> An unset variable is like an empty box with dust in it — whatever you read is garbage.

### 3.7 `const` — a variable you cannot change

```cpp
const double PI = 3.14159;   // ✅ fixed forever
PI = 3.0;                    // ❌ compile error! cannot change const
```

Use `const` for values that should never change (PI, a fixed rate, max size...).

### 3.8 What happens in memory?

```cpp
int age = 25;
double gpa = 3.8;
```

```
Memory (rough view):
┌──────────────┬────────────────────┬──────────────────────┐
│   age        │   gpa              │   ... other stuff    │
│   25         │   3.8              │                      │
│   (4 bytes)  │   (8 bytes)        │                      │
└──────────────┴────────────────────┴──────────────────────┘
  name ──► actual storage location
```

When you write `age`, the compiler replaces it with the memory address, so the CPU can read or write directly.

### 3.9 `cin` — reading input

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter your age: ";   // show a prompt
    cin >> age;                   // read a number from keyboard, store in age

    cout << "You are " << age << " years old." << endl;
    return 0;
}
```

- `cin >> variable;` pauses the program and waits for the user to type a value and press Enter.
- `>>` is the opposite direction of `<<`. "Stream value into the variable."
- You can chain: `cin >> a >> b >> c;` (user types 3 numbers separated by space/enter).

> 💡 **Easy memory trick:** `cout <<` = **out**going (screen shows it).
> `cin >>` = **in**coming (keyboard gives it).
> The arrow always points toward where the data is going.

---

## 4. Operators

An **operator** is a symbol that tells the computer to do an action on values (called **operands**).

```cpp
5 + 3
  └┬┘  └─ operand (right)  ← the + in the middle is the operator
```

### 4.1 Arithmetic operators (math)

| Operator | Meaning | Example | Result |
|----------|---------|---------|--------|
| `+` | add | `7 + 3` | `10` |
| `-` | subtract | `7 - 3` | `4` |
| `*` | multiply | `7 * 3` | `21` |
| `/` | divide | `7 / 2` | `3` (int!) or `3.5` if decimal |
| `%` | **modulo** (remainder) | `7 % 2` | `1` |

**The modulo `%` operator** — very important in DSA!
It gives the **remainder** after division:

```cpp
cout << 7 % 2;     // 1  (7 ÷ 2 = 3 remainder 1)
cout << 10 % 3;    // 1  (10 ÷ 3 = 3 remainder 1)
cout << 10 % 5;    // 0  (10 ÷ 5 = 2 remainder 0)
cout << 5 % 10;    // 5  (5 is smaller than 10, so remainder is 5 itself)
```

**Super useful trick — even or odd:**

```cpp
int n = 7;
if (n % 2 == 0)  cout << "even";    // 7 % 2 = 1, so NOT even
else              cout << "odd";    // ✅ 7 is odd
```

**Another classic use — last digit of a number:**

```cpp
int num = 1234;
cout << num % 10;    // 4  ← last digit!
```

**Watch out — division by zero:**
```cpp
cout << 5 / 0;    // ❌ crashes (runtime error)! zero has no value to divide by.
cout << 5 % 0;    // ❌ also crashes
```

### 4.2 Assignment operators

| Operator | Meaning | Example | Same as |
|----------|---------|---------|---------|
| `=` | assign (put value in box) | `x = 5` | — |
| `+=` | add then assign | `x += 3` | `x = x + 3` |
| `-=` | subtract then assign | `x -= 3` | `x = x - 3` |
| `*=` | multiply then assign | `x *= 3` | `x = x * 3` |
| `/=` | divide then assign | `x /= 3` | `x = x / 3` |
| `%=` | modulo then assign | `x %= 3` | `x = x % 3` |

Example:
```cpp
int x = 10;
x += 5;     // x = 15
x *= 2;     // x = 30
x -= 8;     // x = 22
```

> ⚠️ **Biggest beginner mistake:** `=` vs `==`
> - `=` means **put this value in the box** (assignment).
> - `==` means **are these two values equal?** (comparison — used in if/while).
> Writing `if (x = 5)` is a bug — it *assigns* 5 instead of comparing!

### 4.3 Increment and decrement

| Operator | Meaning | Example | Result |
|----------|---------|---------|--------|
| `++` | add 1 | `x++` or `++x` | x becomes x+1 |
| `--` | subtract 1 | `x--` or `--x` | x becomes x-1 |

```cpp
int i = 5;
i++;        // i = 6
i--;        // i = 5
```

You will see these **everywhere** in loops:
```cpp
for (int i = 0; i < 5; i++)    // i++ means "add 1 after each round"
```

(`++i` and `i++` behave the same in normal beginner code. Don't worry about the tiny difference yet.)

### 4.4 Comparison operators (they give true/false)

| Operator | Meaning | Example | Result |
|----------|---------|---------|--------|
| `==` | equal to | `5 == 5` | `true` |
| `!=` | not equal to | `5 != 3` | `true` |
| `>` | greater than | `5 > 3` | `true` |
| `<` | less than | `5 < 3` | `false` |
| `>=` | greater than or equal | `5 >= 5` | `true` |
| `<=` | less than or equal | `5 <= 4` | `false` |

All of them produce a **bool** (true or false). You'll use them inside `if` and `while`:

```cpp
int age = 18;
if (age >= 18)          // 18 >= 18 → true → runs
    cout << "You can vote!" << endl;
```

### 4.5 Logical operators (combine conditions)

| Operator | Meaning | When it's true |
|----------|---------|----------------|
| `&&` | AND | BOTH sides must be true |
| `\|\|` | OR | AT LEAST ONE side must be true |
| `!` | NOT | flips true ↔ false |

**Truth tables (the full rules):**

`&&` (AND) — "both must be yes":
| A | B | A && B |
|---|---|--------|
| true | true | **true** |
| true | false | false |
| false | true | false |
| false | false | false |

`||` (OR) — "at least one yes":
| A | B | A \|\| B |
|---|---|---------|
| true | true | **true** |
| true | false | **true** |
| false | true | **true** |
| false | false | false |

`!` (NOT) — flip it:
| A | !A |
|---|----|
| true | false |
| false | true |

**Real example — checking if a number is in range:**

```cpp
int n = 50;
if (n >= 0 && n <= 100)     // 50 >= 0 (true) AND 50 <= 100 (true) → true
    cout << "n is between 0 and 100" << endl;
```

**Real example — weekend check:**

```cpp
int day = 6;   // 0=Sunday ... 6=Saturday
if (day == 0 || day == 6)      // 6 == 0 (false) OR 6 == 6 (true) → true
    cout << "It's the weekend!" << endl;
```

**Real example — NOT:**

```cpp
bool isRaining = false;
if (!isRaining)                // !false = true → runs
    cout << "Let's play cricket!" << endl;
```

### 4.6 Operator precedence (who goes first?)

When you mix operators, C++ follows a fixed order (like BODMAS in math):

```
1. ( )          parentheses — highest priority
2. !           NOT
3. *  /  %     multiply, divide, modulo (left to right)
4. +  -        add, subtract (left to right)
5. ==  !=  <  >  <=  >=    comparisons
6. &&          AND
7. ||          OR
8. =  += ...   assignment — lowest priority
```

Example, step by step:

```cpp
int result = 3 + 4 * 2 == 11 && 5 > 3;

Step 1:  4 * 2 = 8                    → 3 + 8 == 11 && 5 > 3
Step 2:  3 + 8 = 11                   → 11 == 11 && 5 > 3
Step 3:  11 == 11 → true             → true && 5 > 3
Step 4:  5 > 3  → true              → true && true
Step 5:  true && true → true        → result = true
```

> 💡 **Rule for beginners:** when in doubt, add parentheses `( )` to show your own order. It never hurts and makes code readable.

---

## 5. Conditional Statements

A **conditional statement** lets your program make decisions: *"do THIS if a condition is true, otherwise do THAT."*

Think of it as a fork in the road. The program checks a condition and picks exactly one path.

```
            ┌───────────────┐
   program ─►  IF condition  ─true──►  Path A (do this)
            └───────────────┘
                   │
                  false
                   │
                   ▼
            Path B (do this instead)
```

### 5.1 Simple `if`

Syntax:
```cpp
if (condition) {
    // runs ONLY when condition is true
}
```

Example — voting age check:
```cpp
#include <iostream>
using namespace std;

int main() {
    int age = 20;

    if (age >= 18) {
        cout << "You can vote!" << endl;   // ✅ runs, because 20 >= 18 is true
    }

    return 0;
}
```

**Step by step:**
1. `age >= 18` → `20 >= 18` → `true`
2. Since true, the block inside `{ }` runs.
3. If `age` were `15`, the condition would be `false` and the block would be **skipped completely**.

### 5.2 `if...else`

Syntax:
```cpp
if (condition) {
    // runs when condition is true
} else {
    // runs when condition is false
}
```

Example — pass/fail:
```cpp
int marks = 45;

if (marks >= 50) {
    cout << "PASS" << endl;      // skipped (45 >= 50 is false)
} else {
    cout << "FAIL" << endl;      // ✅ this runs
}
```

**Step by step:**
1. Check `marks >= 50` → `45 >= 50` → `false`
2. `false` → skip the `if` block, go to the `else` block.
3. `else` always runs when `if` does not. Exactly **one** path runs — never both.

### 5.3 `if...else if...else` (ladder of conditions)

Use it when there are **more than two** possibilities:

```cpp
if (condition1) {
    // case 1
} else if (condition2) {
    // case 2
} else if (condition3) {
    // case 3
} else {
    // nothing above matched → default case
}
```

**How it works step by step (the ladder):**
1. Check condition1. True? Run it and STOP (skip everything below).
2. False? Check condition2. True? Run it and STOP.
3. False? Check condition3...
4. All false? Run the final `else`.

Example — grading marks:
```cpp
int marks = 82;

if (marks >= 90) {
    cout << "Grade: A" << endl;
} else if (marks >= 75) {
    cout << "Grade: B" << endl;
} else if (marks >= 50) {
    cout << "Grade: C" << endl;      // ⚠️ order matters! (see below)
} else {
    cout << "Grade: F" << endl;
}
// 82:  82>=90 false → 82>=75 TRUE → prints "Grade: B" ✅
```

⚠️ **Order matters a lot!** Imagine you reversed the ladder:
```cpp
if (marks >= 50) {          // 82 >= 50 → TRUE → prints C and STOPS
    cout << "Grade: C" << endl;
} else if (marks >= 75) {   // never reached for 82 ❌
    cout << "Grade: B" << endl;
}
```
An 82-mark student would get grade C! **Always put the strongest/most specific condition first.**

Example — day of week (using `||`):
```cpp
int day = 3;    // 0=Sunday, 1=Monday, ... 6=Saturday

if (day == 0 || day == 6) {
    cout << "Weekend!" << endl;
} else {
    cout << "Working day." << endl;   // ✅ 3 is neither 0 nor 6
}
```

### 5.4 Nested `if` (if inside if)

Sometimes a decision needs a second check inside the first:

```cpp
int age = 20;
bool hasLicense = true;

if (age >= 18) {
    cout << "You are an adult." << endl;
    if (hasLicense) {                        // second check INSIDE the first
        cout << "And you can drive!" << endl;  // ✅ both true → both print
    } else {
        cout << "But you cannot drive yet." << endl;
    }
}
```

**Step by step:**
1. `age >= 18` → true → enter outer block, print "adult"
2. Inside: `hasLicense` → true → print "can drive"
3. If `hasLicense` were false, only "adult" would print.
4. If `age < 18`, the whole outer block (and everything inside it) is skipped.

> 💡 **Easy memory trick:** `if` = the bouncer at the door.
> He checks one question. Yes? You get in. No? You go to the `else` side.
> `else if` = a second bouncer with a different question.
> The first YES you meet wins, and the rest are never asked.

### 5.5 `switch` — a cleaner way for many equal-value checks

When you compare **one variable against many fixed values**, `switch` is cleaner than a long `else if` ladder:

```cpp
int day = 2;

switch (day) {
    case 0:  cout << "Sunday" << endl;    break;
    case 1:  cout << "Monday" << endl;    break;
    case 2:  cout << "Tuesday" << endl;   break;   // ✅ day==2 → runs this
    case 3:  cout << "Wednesday" << endl; break;
    case 4:  cout << "Thursday" << endl;  break;
    case 5:  cout << "Friday" << endl;    break;
    case 6:  cout << "Saturday" << endl;  break;
    default: cout << "Not a valid day" << endl;   // no case matched → here
}
```

**Step by step:**
1. `switch (day)` — look at the value of `day` (which is 2).
2. Jump straight to `case 2:` (no checking of cases 0 or 1!).
3. Run that line, then `break` stops the switch.
4. If `day` were `9`, no case matches → `default` runs.

**Rules:**
- Works only with **whole numbers and characters** (int, char) — not with strings or ranges.
- `break` is essential — without it, execution **falls through** to the next case (this is sometimes a feature, usually a bug).
- `default` is like the final `else` — optional but recommended.

### 5.6 Common beginner mistakes

```cpp
// ❌ MISTAKE 1: forgot the semicolon after if ( )
if (x > 5)        ← missing ; here → compile error
    cout << "big";

// ❌ MISTAKE 2: `=` instead of `==`
if (x = 5)        // this ASSIGNS 5 to x, then checks it → almost always true

// ❌ MISTAKE 3: single line without braces + adding more later
if (x > 5)
    cout << "big";      // only THIS line belongs to the if
    cout << "always";    // this runs ALWAYS (common logic bug!)

// ✅ Fix: always use braces
if (x > 5) {
    cout << "big";
    cout << "also only when big";
}
```

> 📌 **Habit: ALWAYS put `{ }` around the body of if/else, even for one line.** It prevents 90% of logic bugs.

---

## 6. Loops

A **loop** repeats a block of code many times without you writing it again and again.

Why do we need loops? Imagine printing the numbers 1 to 100.
Without a loop you'd type 100 lines of `cout`. With a loop: 5 lines. 🎯

There are 3 kinds of loops in C++: `for`, `while`, and `do-while`. The first two cover 99% of beginner work.

### 6.1 `for` loop (count-based repetition)

**Use it when you KNOW how many times you want to repeat.**

Syntax:
```cpp
for (initialization; condition; update) {
    // body — runs again and again while condition is true
}
```

The 3 parts mean:
1. **initialization** — set the counter once at the start (e.g. `i = 0`)
2. **condition** — checked BEFORE every round; if false, loop ENDS
3. **update** — runs at the END of every round (e.g. `i++`)

**Example — print 0 to 4:**
```cpp
for (int i = 0; i < 5; i++) {
    cout << i << " ";    // prints: 0 1 2 3 4
}
cout << endl;
```

**Step by step (this is the most important part — follow it):**

| Round | Start: i = ? | Check i < 5? | Body runs (prints) | End: i++ |
|-------|--------------|--------------|--------------------|----------|
| 1 | i = 0 (init) | 0 < 5 → ✅ true | prints 0 | i becomes 1 |
| 2 | — | 1 < 5 → ✅ true | prints 1 | i becomes 2 |
| 3 | — | 2 < 5 → ✅ true | prints 2 | i becomes 3 |
| 4 | — | 3 < 5 → ✅ true | prints 3 | i becomes 4 |
| 5 | — | 4 < 5 → ✅ true | prints 4 | i becomes 5 |
| 6 | — | 5 < 5 → ❌ false | **loop stops** | — |

So it prints exactly `0 1 2 3 4` and stops when `i` becomes 5.

**Example — sum of 1 to 100:**
```cpp
int sum = 0;
for (int i = 1; i <= 100; i++) {
    sum = sum + i;      // add each number to the running total
}
cout << "Sum = " << sum << endl;   // prints: Sum = 5050
```

**Example — print in reverse (10 to 1):**
```cpp
for (int i = 10; i >= 1; i--) {    // i-- means "subtract 1 each round"
    cout << i << " ";              // prints: 10 9 8 7 6 5 4 3 2 1
}
cout << endl;
```

**Example — step by 2 (only even numbers):**
```cpp
for (int i = 2; i <= 10; i += 2) {
    cout << i << " ";              // prints: 2 4 6 8 10
}
cout << endl;
```

### 6.2 `while` loop (condition-based repetition)

**Use it when you do NOT know in advance how many times to repeat** — just "keep going while this is true."

Syntax:
```cpp
initialization;            // set counter before the loop
while (condition) {        // check before EVERY round
    body;                  // runs while condition is true
    update;                // change something, or the loop never ends!
}
```

**Example — same 0 to 4, with while:**
```cpp
int i = 0;                // 1. initialize BEFORE the loop
while (i < 5) {           // 2. check condition
    cout << i << " ";     //    body → prints: 0 1 2 3 4
    i++;                  // 3. update (FORGET THIS = INFINITE LOOP!)
}
cout << endl;
```

**`for` vs `while` — same power, different style:**

| Situation | Use |
|-----------|-----|
| You know the count ("repeat 10 times") | `for` ✅ |
| Unknown count ("until user enters correct password") | `while` ✅ |
| DSA problems (loops with counters) | `for` ✅ |

> ⚠️ **Infinite loop trap:** in a `while` loop, if you forget `i++`, the condition stays true forever and the program hangs. In a `for` loop it's hard to forget because all 3 parts sit right there on one line. That's why `for` is the beginner favorite.

### 6.3 `do-while` loop (check AFTER running)

Runs the body **at least once**, then checks the condition:

```cpp
do {
    body;                  // runs FIRST (guaranteed at least once)
    update;
} while (condition);       // THEN checks; true → repeat
```

**Example — keep asking until a positive number is entered:**
```cpp
int n;
do {
    cout << "Enter a positive number: ";
    cin >> n;
} while (n <= 0);          // even if the FIRST input is bad, we still ask

cout << "Good: " << n << endl;
```

Difference from `while`: with `while`, if the condition is false from the start, the body runs **zero times**. With `do-while`, the body ALWAYS runs at least once.

### 6.4 Nested loops (loop inside loop — the most important DSA loop!)

A loop inside a loop. The **inner loop finishes completely** for each single step of the outer loop.

**Example — print 0 1 2 three times:**
```cpp
for (int i = 0; i < 3; i++) {          // outer: 3 rounds
    for (int j = 0; j < 3; j++) {      // inner: 3 rounds EACH time
        cout << j << " ";
    }
    cout << endl;                       // new line after each inner loop
}
```

Output:
```
0 1 2
0 1 2
0 1 2
```

**Step by step:**
```
Outer round 1 (i=0):
    inner: j=0 → print 0
    inner: j=1 → print 1
    inner: j=2 → print 2
    inner: j=3 → stop, print new line
Outer round 2 (i=1):
    inner runs again fully → 0 1 2 + new line
Outer round 3 (i=2):
    inner runs again fully → 0 1 2 + new line
Outer: i=3 → stop
```

**Total body runs = outer rounds × inner rounds = 3 × 3 = 9.**
This multiplication is the key to understanding **time complexity** later (n × n = O(n²)).

### 6.5 `break` and `continue`

**`break` — escape the loop immediately (like a door out).**
```cpp
for (int i = 0; i < 100; i++) {
    if (i == 5) {
        break;               // stop the whole loop NOW, even though i < 100
    }
    cout << i << " ";        // prints: 0 1 2 3 4  (never reaches 5 or above)
}
cout << endl;
```

Use case: stop as soon as you find what you're looking for (like in search!)

**`continue` — skip just THIS round, go to the next one.**
```cpp
for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0) {
        continue;            // even number? skip the rest of this round
    }
    cout << i << " ";        // prints only odd: 1 3 5 7 9
}
cout << endl;
```

| Keyword | Effect |
|---------|--------|
| `break` | **ends** the loop entirely, jumps to the line after it |
| `continue` | **skips the rest of this round**, jumps to the next round |

> 💡 **Easy memory trick:** `break` = smashing the door and leaving the room.
> `continue` = "this round is boring, next!" — you stay in the room.

---

## 7. Pattern Printing

Patterns are nested-loop practice problems. Mastering them = mastering nested loops + conditions.

**The mental model for every pattern:**
- Outer loop = **rows** (how many lines)
- Inner loop = **what to print in that row**
- A `cout << endl;` after the inner loop = one finished row

> 📌 **Golden rule:** figure out the formula "row n contains WHAT?" first, then write the loops. Never guess — derive.

### 7.1 Pattern 1 — solid square

For n = 4:
```
* * * *
* * * *
* * * *
* * * *
```

**Formula:** every row has n stars. Row number doesn't change anything.

```cpp
int n = 4;
for (int i = 1; i <= n; i++) {        // n rows
    for (int j = 1; j <= n; j++) {    // n stars per row
        cout << "* ";
    }
    cout << endl;                      // finish the row
}
```

**Step by step (first row):**
1. Outer: i=1 (row 1)
2. Inner: j=1 → print `* `; j=2 → print `* `; j=3 → `* `; j=4 → `* `; j=5 → stop
3. Row 1 complete: `* * * *` + newline
4. Rows 2, 3, 4 repeat the exact same inner loop

### 7.2 Pattern 2 — right triangle (increasing)

For n = 4:
```
*
* *
* * *
* * * *
```

**Formula:** row i contains **i** stars. (Row 1 → 1 star, row 2 → 2 stars...)

```cpp
int n = 4;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {    // ⚠️ j goes up to i, NOT n!
        cout << "* ";
    }
    cout << endl;
}
```

**Step by step (row 2):**
1. Outer: i=2 → this row should have 2 stars
2. Inner condition: `j <= i` → `j <= 2` → j runs 1, 2 → prints exactly 2 stars
3. Row 2 = `* *` ✅

### 7.3 Pattern 3 — right triangle (decreasing)

For n = 4:
```
* * * *
* * *
* *
*
```

**Formula:** row i contains **(n - i + 1)** stars. (Row 1 → 4, row 2 → 3, row 3 → 2, row 4 → 1)

```cpp
int n = 4;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i + 1; j++) {
        cout << "* ";
    }
    cout << endl;
}
```

### 7.4 Pattern 4 — decreasing triangle with leading spaces

For n = 4:
```
 * * * *
  * * *
   * *
    * *
```

**Formula for row i:**
- leading spaces = **i** (row 1 → 1 space, row 2 → 2 spaces...)
- stars = **n - i + 1** (4, 3, 2, 1)


```cpp
int n = 4;
for (int i = 1; i <= n; i++) {
    // Part A: print i spaces
    for (int j = 1; j <= i; j++) {
        cout << "  ";          // two spaces per step keeps alignment
    }
    // Part B: print (n - i + 1) stars
    for (int j = 1; j <= n - i + 1; j++) {
        cout << "* ";
    }
    cout << endl;
}
```

**The key technique:** a row = **Part A (spaces) + Part B (stars)**, each with its own inner loop. This "two inner loops in one row" structure appears in almost every fancy pattern.

### 7.5 Pattern 5 — pyramid (mountain)

For n = 4:
```
      *
     * * *
    * * * * *
   * * * * * * *
```

**Formula for row i (i from 1 to n):**
- leading spaces = **n - i**
- stars = **2i - 1** (1, 3, 5, 7... always odd — that's what makes it a pyramid!)

```cpp
int n = 4;
for (int i = 1; i <= n; i++) {
    // Part A: spaces = n - i
    for (int j = 1; j <= n - i; j++) {
        cout << " ";
    }
    // Part B: stars = 2*i - 1
    for (int j = 1; j <= 2 * i - 1; j++) {
        cout << "* ";
    }
    cout << endl;
}
```

**Step by step (row 3 of n=4):**
1. Spaces = 4 - 3 = **1** → print 1 space
2. Stars = 2×3 - 1 = **5** → print 5 stars
3. Row 3 = ` * * * * *` ✅ (1 leading space, 5 stars)

### 7.6 Pattern 6 — numbers instead of stars

For n = 4 (each row prints its row number):
```
1
2 2
3 3 3
4 4 4 4
```

**Only change:** the inner loop prints `i` instead of `*`. The loop structure is exactly Pattern 2 (triangle).

```cpp
int n = 4;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
        cout << i << " ";      // print the ROW NUMBER, not '*'
    }
    cout << endl;
}
```

Another variant — repeat the row number i times vs. a running counter:
```
1
2 3
4 5 6
7 8 9 10
```
Here the inner loop just keeps printing a running number:
```cpp
int n = 4;
int num = 1;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
        cout << num++ << " ";   // print then increment
    }
    cout << endl;
}
```

### 7.7 Pattern 7 — hollow square

For n = 4:
```
* * * *
*    *
*    *
* * * *
```

**Formula:** a cell is a `*` if it's on the **border** (row 1, row n, column 1, column n); otherwise a space.

This is where **conditions inside loops** enter the pattern world:

```cpp
int n = 4;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        if (i == 1 || i == n || j == 1 || j == n) {
            cout << "* ";      // border → star
        } else {
            cout << "  ";      // inside → space
        }
    }
    cout << endl;
}
```

**Step by step (cell i=2, j=2):**
1. Is i==1? No. Is i==4? No. Is j==1? No. Is j==4? No.
2. None true → it's inside → print a space ✅

**Step by step (cell i=2, j=4):**
1. Is j==4? YES → print a star ✅ (right border)

### 7.8 Pattern 8 — Floyd's triangle

For n = 4:
```
1
2 3
4 5 6
7 8 9 10
```
(Same as the running-counter variant in 7.6 — a classic DSA pattern problem.)

### 7.9 How to solve ANY pattern (the 4-step method)

1. **Count the rows.** How many lines does the target have? → outer loop limit.
2. **Analyze one row.** What does row i contain? Count spaces, stars, numbers. Write the formula with `i`.
3. **Build the row.** One inner loop per "part" of the row (spaces part, stars part, numbers part).
4. **End the row** with `cout << endl;`, then let the outer loop repeat.

> 💡 **Easy memory trick:** Outer loop = floors of a building (rows).
> Inner loop = laying the bricks of that floor (the row content).
> `endl` = moving to the next floor.

---

## 8. Functions

A **function** is a named, reusable block of code that does ONE job. You write it once, then call it as many times as you want.

Think of it like a **microwave**: you press a button (call the function), it does the cooking inside (runs the code), and gives you the result (returns a value). You don't need to understand the heating element every time — you just use it.

### 8.1 Why use functions?

1. **Reuse** — write the code once, call it 100 times.
2. **Smaller programs** — instead of one giant `main`, you get small, named jobs.
3. **Easier to find bugs** — a problem in "calculate area" is in `calculateArea`, not somewhere in 500 lines.
4. **DSA problems almost always require functions** (like the search functions in this guide!).

### 8.2 Anatomy of a function

```cpp
returnType  functionName ( parameterList ) {
    // body — the code that does the job
    return value;          // (only if returnType is not void)
}
```

Real example:

```cpp
int add(int a, int b) {      // ← this is the "function definition"
    int sum = a + b;
    return sum;              // ← hands the answer back
}
```

Piece by piece:
- `int` → **return type**: "I will give back a whole number."
- `add` → **function name** (your own name for this job).
- `(int a, int b)` → **parameters** (the inputs it needs). `a` and `b` are local copies that exist only inside the function.
- `{ ... }` → **body**: the steps it performs.
- `return sum;` → **gives back the result** and instantly exits the function.

### 8.3 Calling a function ("using" it)

```cpp
#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    int x = add(3, 5);        // CALL: pass 3 and 5, receive the result
    cout << "3 + 5 = " << x << endl;   // prints: 3 + 5 = 8

    int y = add(10, 20);      // same function, different inputs
    cout << "10 + 20 = " << y << endl;  // prints: 10 + 20 = 30

    return 0;
}
```

**Step by step for `add(3, 5)`:**
1. `main` says: "run the job `add` with a=3, b=5."
2. Inside `add`: `sum = 3 + 5 = 8`.
3. `return sum;` → hands `8` back to `main`.
4. Back in `main`: `x` receives `8`.
5. `main` continues with the next line.

### 8.4 `void` functions (no result given back)

If a function just DOES something (prints, draws) and doesn't hand back a value, use `void` and skip `return`:

```cpp
void printLine() {
    cout << "====================" << endl;   // job: print a line
    // no return needed — void means "I give nothing back"
}

int main() {
    printLine();          // call (note: no value received)
    cout << "My Report" << endl;
    printLine();          // call again — reuse!
    return 0;
}

// Output:
// ====================
// My Report
// ====================
```

### 8.5 Parameters in detail — passing by value

When you call `add(3, 5)`, C++ makes **copies** of your values inside the function. Changing the copy does NOT change the original:

```cpp
void changeIt(int n) {
    n = 999;             // change the COPY
    cout << "inside: " << n << endl;   // inside: 999
}

int main() {
    int myNum = 5;
    changeIt(myNum);                 // passes a COPY of 5
    cout << "outside: " << myNum << endl;   // outside: 5  ← unchanged!
    return 0;
}
```

**Step by step:**
1. `changeIt(myNum)` → C++ copies `5` into the parameter `n`.
2. Inside: `n = 999` → only the copy changes.
3. Function ends → the copy `n` is destroyed.
4. `myNum` still holds `5`. ✅

> This is called **pass by value**. It's the default. (You'll meet "pass by reference" when you learn pointers below.)

### 8.6 Multiple return values? Use parameters as "output"

C++ can only `return` one value. Trick: pass a variable's *address* (a pointer) and change it from inside — you'll learn this fully in the pointers section. A common beginner workaround:

```cpp
// return the bigger number, put the smaller one into &small
int bigger(int a, int b, int &small) {
    if (a > b) { small = b; return a; }
    else       { small = a; return b; }
}

int main() {
    int small;
    int big = bigger(30, 70, small);
    cout << "big=" << big << " small=" << small << endl;   // big=70 small=30
    return 0;
}
```

(If `&small` looks scary right now, just remember: it lets the function change YOUR variable. The pointers section explains it.)

### 8.7 Local vs global variables

```cpp
int globalCount = 100;        // GLOBAL: exists everywhere, lives whole program

void myFunc() {
    int localVar = 5;         // LOCAL: exists ONLY inside myFunc
}

int main() {
    cout << globalCount << endl;      // ✅ works — global is visible here
    cout << localVar << endl;         // ❌ compile error! localVar doesn't exist here
    return 0;
}
```

Rules:
- **Local variables** (inside a function) exist only while that function runs. When the function ends, they are destroyed.
- **Global variables** exist for the whole program.
- If a local and global have the same name, the local one **shadows** (hides) the global inside that function.
- ⚠️ DSA tip: in competitive programming, prefer locals — fewer surprises.

### 8.8 Function overloading (same name, different parameters)

C++ allows several functions with the **same name** as long as their parameter lists differ:

```cpp
int add(int a, int b) { return a + b; }                 // two ints
int add(int a, int b, int c) { return a + b + c; }      // three ints

int main() {
    cout << add(2, 3) << endl;       // calls the 2-INT version → 5
    cout << add(2, 3, 4) << endl;    // calls the 3-INT version → 9
    return 0;
}
```

The compiler picks the right one by looking at **how many and what type** of arguments you pass.

### 8.9 Complete mini-project: simple calculator

Putting it all together (functions + conditions + loops):

```cpp
#include <iostream>
using namespace std;

int add(int a, int b)   { return a + b; }
int sub(int a, int b)   { return a - b; }
int mul(int a, int b)   { return a * b; }
int divi(int a, int b)  { return a / b; }

int main() {
    int a, b, choice;

    cout << "Simple Calculator" << endl;
    cout << "1. Add  2. Subtract  3. Multiply  4. Divide" << endl;
    cout << "Choose (1-4): ";
    cin >> choice;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    if (choice == 1)      cout << a << " + " << b << " = " << add(a, b) << endl;
    else if (choice == 2) cout << a << " - " << b << " = " << sub(a, b) << endl;
    else if (choice == 3) cout << a << " * " << b << " = " << mul(a, b) << endl;
    else if (choice == 4) {
        if (b == 0)       cout << "Cannot divide by zero!" << endl;
        else              cout << a << " / " << b << " = " << divi(a, b) << endl;
    }
    else                  cout << "Invalid choice" << endl;

    return 0;
}
```

**Step by step (user picks 1, enters 7 and 3):**
1. `choice = 1`, `a = 7`, `b = 3`.
2. `choice == 1` → true → run `cout << ... add(7,3) ...`
3. `add(7,3)` returns `10`.
4. Print: `7 + 3 = 10` ✅

> 💡 **Easy memory trick:** A function is a recipe card.
> `parameters` = ingredients you hand over. `body` = the cooking steps.
> `return` = the finished dish handed back. You can use the same recipe card forever.

---

## 9. Binary Number System

### 9.1 What is binary?

Every number in your computer is stored as a long string of just two digits: **0 and 1**.
That's the **binary** (base-2) number system.

- **Decimal** (what humans use) = base **10** → digits 0-9, each position is a power of 10.
- **Binary** (what computers use) = base **2** → digits 0-1, each position is a power of 2.

Why binary? Because a computer is made of tiny switches (transistors) that are either **ON (1)** or **OFF (0)**. Two states = base 2. Perfect match.

### 9.2 Place values in decimal (to understand the idea)

The number `4527` in decimal:

```
  4       5       2       7
× 1000   × 100   × 10    × 1        ← powers of 10
= 4000  + 500   + 20    + 7
= 4527
```

Each digit × the place value (a power of 10). **Same idea, but with powers of 2 → binary.**

### 9.3 Binary place values (powers of 2) — MEMORIZE THESE

| Position (from right) | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|---|---|---|---|---|---|---|---|---|
| **Value** | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |

> 📌 These 8 numbers (1, 2, 4, 8, 16, 32, 64, 128) are the most used numbers in all of DSA. Memorize them!

### 9.4 Binary → Decimal (converting to human numbers)

**Rule:** each binary digit × its place value, then add everything.

**Example: `1011` (binary) = ?**

```
  1       0       1       1
× 8     × 4     × 2     × 1
= 8     + 0     + 2     + 1
= 11   ✅
```
So `1011₂` = `11₁₀` (subscript means base: ₂ = binary, ₁₀ = decimal).

**Example: `11010` (binary) = ?**

```
  1       1       0       1       0
× 16    × 8     × 4     × 2     × 1
= 16    + 8     + 0     + 2     + 0
= 26   ✅
```

### 9.5 Decimal → Binary (the division-by-2 method)

**Rule:** keep dividing by 2, write down the **remainders**, then read them **bottom to top**.

**Example: 13 (decimal) = ? (binary)**

```
  13 ÷ 2 = 6   remainder 1   ← last (rightmost) bit
   6 ÷ 2 = 3   remainder 0
   3 ÷ 2 = 1   remainder 1
   1 ÷ 2 = 0   remainder 1   ← first (leftmost) bit
```

Read remainders **bottom → top**: `1101` ✅

**Check it back:** 8 + 4 + 0 + 1 = 13 ✅

**Example: 42 (decimal)**

```
  42 ÷ 2 = 21  remainder 0
  21 ÷ 2 = 10  remainder 1
  10 ÷ 2 = 5   remainder 0
   5 ÷ 2 = 2   remainder 1
   2 ÷ 2 = 1   remainder 0
   1 ÷ 2 = 0   remainder 1
```

Bottom to top: `101010` ✅

**Check:** 32 + 8 + 2 = 42 ✅

### 9.6 A faster trick for decimal → binary

You already memorized the powers of 2 (1, 2, 4, 8, 16, 32, 64, 128). Use them greedily!

**Example: 45 = ?**
1. Biggest power of 2 in 45 is **32** → put a 1 at the 32 place. 45 - 32 = 13 left.
2. Biggest power in 13 is **8** → 1 at the 8 place. 13 - 8 = 5 left.
3. Biggest power in 5 is **4** → 1 at the 4 place. 5 - 4 = 1 left.
4. Biggest power in 1 is **1** → 1 at the 1 place. 0 left. Done!

Fill in the gaps with 0:

| 32 | 16 | 8 | 4 | 2 | 1 |
|----|----|---|---|---|---|
| 1  | 0  | 1 | 1 | 0 | 1 |

→ `101101` ✅ (32+8+4+1 = 45 ✅)

### 9.7 Bit, byte, and common sizes

- **1 bit** = one binary digit (0 or 1).
- **1 byte = 8 bits** (that's why 1 byte can hold values 0 to 255 = 2⁸ - 1).
- `int` = 4 bytes = 32 bits → values from -2,147,483,648 to +2,147,483,647 (that's 2³¹).
- `long long` = 8 bytes = 64 bits.

That's where the data type ranges from Section 2 come from! `2^31` ≈ 2.1 billion.

### 9.8 Binary addition (how the computer adds!)

Rules (just like decimal, but base 2):
```
0 + 0 = 0
0 + 1 = 1
1 + 0 = 1
1 + 1 = 10   → write 0, carry 1  (like 1+1=10 in decimal!)
1 + 1 + 1 = 11 → write 1, carry 1  (with an incoming carry)
```

**Example: 1011 (11) + 110 (6) = ?**

```
    1 0 1 1
  +   1 1 0
  ---------
from right:
  1 + 0 = 1          → 1
  1 + 1 = 10         → write 0, carry 1
  0 + 1 + 1(carry) = 10 → write 0, carry 1
  1 + 0 + 1(carry) = 10 → write 0, carry 1
  carry 1            → write 1

result: 1 0 0 0 1   = 10001₂ = 16 + 1 = 17 ✅  (11 + 6 = 17 ✅)
```

### 9.9 Binary & DSA: why you'll meet this everywhere

- **Bit manipulation** problems: "is this number odd?" → check the last bit (`n & 1`).
- `n % 2` and `n & 1` give the same answer (odd/even).
- `n / 2` (integer division) and `n >> 1` (shift right by 1) do the same thing.
- Powers of 2 (1, 2, 4, 8, ...) appear in array indexes, binary search halves, and tree levels.

**Quick examples of the shift/and equivalents (preview!):**
```cpp
int n = 10;            // binary: 1010
cout << n & 1;         // 0  → even  (last bit is 0)
cout << 7 & 1;         // 1  → odd   (last bit is 1)
cout << n >> 1;        // 5  → same as 10 / 2
cout << 1 << 4;        // 16 → same as 2^4
```

> 💡 **Easy memory trick:** Binary = decimal, but the place values are 1, 2, 4, 8, 16... instead of 1, 10, 100.
> Converting to decimal = "turn on" the place values where you see a 1, and add them up.
> Converting from decimal = "which of my memorized powers add up to this number?"

---

## 10. Arrays

### 10.1 What is an array?

An **array** is a way to store **many values of the same type in one place**, one after another, in memory.

Why do we need arrays? Imagine storing the marks of 10 students.

**Without an array** — 10 different variables:
```cpp
int s1 = 70;
int s2 = 85;
int s3 = 92;
// ... 7 more variables
```

**With an array** — just one:
```cpp
int marks[10];   // one variable that holds 10 numbers
```

### 10.2 How does it look in memory?

An array is stored as **one continuous block of memory**. Each box is an **element**, and each element has a number called an **index**.

```
Array:  { 10, 20, 30, 40, 50 }

Memory boxes:
┌────────┬────────┬────────┬────────┬────────┐
│  10    │  20    │  30    │  40    │  50    │
└────────┴────────┴────────┴────────┴────────┘
  index 0    index 1   index 2   index 3   index 4
```

### 10.3 Important rules

- Index starts from **0**, not 1.
- An array with `n` elements has valid indexes from `0` to `n-1`.
- The **last index** is always `size - 1`.
- Accessing an element is **instant** — this is called **O(1) access**.
  Example: `arr[3]` gives you the 4th value directly, no counting needed.

> 💡 **Easy memory trick:** Think of an array like a row of lockers.
> Each locker has a number (the index), and you can open any locker
> immediately by its number — locker 0, locker 1, locker 50...

### 10.4 How to make and use an array in C++

**Creating an array:**
```cpp
int arr[] = {1, 2, 3, 4, 5};   // array of 5 integers
```

**Finding the size:**
```cpp
int n = sizeof(arr) / sizeof(int);   // n = 5
```
How it works:
- `sizeof(arr)` → total size in bytes (5 integers = 20 bytes)
- `sizeof(int)` → size of one integer (4 bytes)
- `20 / 4 = 5` → number of elements ✅

**Reading and changing elements:**
```cpp
int value = arr[2];    // read  the element at index 2  → value = 3
arr[2] = 99;           // change the element at index 2  → arr[2] = 99
```

**Printing the whole array (using a loop from Section 6!):**
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

**Step by step for the print loop:**
1. `i = 0` → `0 < 5` true → print `arr[0]` = 1
2. `i = 1` → print `arr[1]` = 2
3. `i = 2` → print `arr[2]` = 3
4. `i = 3` → print `arr[3]` = 4
5. `i = 4` → print `arr[4]` = 5
6. `i = 5` → `5 < 5` false → loop ends. ✅

⚠️ **Common bug — off by one:**
```cpp
for (int i = 0; i <= n; i++) {   // ❌ i goes 0,1,2,3,4,5
    cout << arr[i];               // arr[5] does NOT exist! garbage/crash
}
// ✅ fix: use i < n, because the last valid index is n-1
```

### 10.5 Passing arrays to functions

Remember Section 8 (functions)? Arrays are passed **by reference** automatically (the function gets the real array, not a copy). So a function can **change the original** array:

```cpp
void doubleAll(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] * 2;      // changes the REAL array
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    doubleAll(arr, n);            // call it

    for (int i = 0; i < n; i++)   // prints: 2 4 6 8 10
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
```

(The `int *arr` part is a **pointer** — explained fully in Section 11's context. For now, just know: this syntax means "give me the array.")

---
