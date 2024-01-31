#include <stdio.h>

// Function to calculate the factorial of a number using recursion
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    // Test case
    int num = 5;

    // Calculate the factorial using recursion
    unsigned long long result = factorial(num);

    // Print the result
    printf("Factorial of %d is %llu\n", num, result);

    return 0;
}
