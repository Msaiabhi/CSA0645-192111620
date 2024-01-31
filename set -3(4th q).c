#include <stdio.h>

// Function to calculate the factorial of a number
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the binomial coefficient (n choose k)
unsigned long long binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to generate Pascal's Triangle
void generatePascalsTriangle(int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%llu ", binomialCoefficient(i, j));
        }
        printf("\n");
    }
}

int main() {
    int rows = 5;

    printf("Pascal's Triangle for %d rows:\n", rows);
    generatePascalsTriangle(rows);

    return 0;
}
