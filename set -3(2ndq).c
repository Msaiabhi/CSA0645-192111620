#include <stdio.h>

// Function to find GCD using Euclidean algorithm recursively
int findGCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return findGCD(b, a % b);
    }
}

int main() {
    // Test Case A
    int a1 = 36, b1 = 48;
    printf("Test Case A: GCD of %d and %d is %d\n", a1, b1, findGCD(a1, b1));

    // Test Case B
    int a2 = 156, b2 = 90;
    printf("Test Case B: GCD of %d and %d is %d\n", a2, b2, findGCD(a2, b2));

    // Test Case C
    int a3 = -56, b3 = 88;
    printf("Test Case C: GCD of %d and %d is %d\n", a3, b3, findGCD(a3, b3));

    return 0;
}
