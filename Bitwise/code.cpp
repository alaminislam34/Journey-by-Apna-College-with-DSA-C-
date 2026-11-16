#include <iostream>
#include <vector>
using namespace std;

// 1. Check Odd / Even using bits
bool isOdd(int n) {
    return (n & 1) != 0;
}

// 2. Check if i-th bit is set (0 or 1)
bool checkBit(int n, int i) {
    return (n & (1 << i)) != 0;
}

// 3. Set i-th bit to 1
int setBit(int n, int i) {
    return n | (1 << i);
}

// 4. Clear i-th bit to 0
int clearBit(int n, int i) {
    return n & ~(1 << i);
}

// 5. Toggle i-th bit (0->1 or 1->0)
int toggleBit(int n, int i) {
    return n ^ (1 << i);
}

// 6. Check if number is Power of 2
bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

// 7. Count set bits (Brian Kernighan's Algorithm)
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main() {
    cout << "===== Bitwise Operators Demo =====" << endl;

    int a = 5; // 0101 in binary
    int b = 6; // 0110 in binary

    cout << "a = 5 (0101), b = 6 (0110)\n";
    cout << "a & b  = " << (a & b)  << " (Expected: 4)\n";
    cout << "a | b  = " << (a | b)  << " (Expected: 7)\n";
    cout << "a ^ b  = " << (a ^ b)  << " (Expected: 3)\n";
    cout << "~a     = " << (~a)     << " (Expected: -6)\n";
    cout << "a << 1 = " << (a << 1) << " (Expected: 10)\n";
    cout << "a >> 1 = " << (a >> 1) << " (Expected: 2)\n";

    cout << "\n===== Bitwise Tricks Demo =====" << endl;
    cout << "Is 7 odd?  " << (isOdd(7) ? "Yes" : "No") << endl;
    cout << "Is 8 odd?  " << (isOdd(8) ? "Yes" : "No") << endl;

    int n = 9; // binary: 1001
    cout << "\nNumber n = 9 (binary: 1001)\n";
    cout << "Is 0th bit set? " << (checkBit(n, 0) ? "Yes" : "No") << endl;
    cout << "Is 1st bit set? " << (checkBit(n, 1) ? "Yes" : "No") << endl;

    n = setBit(n, 1); // 1001 -> 1011 (11)
    cout << "After setting 1st bit: " << n << endl;

    n = clearBit(n, 0); // 1011 -> 1010 (10)
    cout << "After clearing 0th bit: " << n << endl;

    n = toggleBit(n, 2); // 1010 -> 1110 (14)
    cout << "After toggling 2nd bit: " << n << endl;

    cout << "\nIs 16 a power of 2? " << (isPowerOfTwo(16) ? "Yes" : "No") << endl;
    cout << "Is 18 a power of 2? " << (isPowerOfTwo(18) ? "Yes" : "No") << endl;

    cout << "Number of set bits in 15 (1111): " << countSetBits(15) << endl;

    // XOR Swap demo
    int x = 10, y = 20;
    cout << "\nBefore swap: x = " << x << ", y = " << y << endl;
    x ^= y;
    y ^= x;
    x ^= y;
    cout << "After swap:  x = " << x << ", y = " << y << endl;

    return 0;
}

