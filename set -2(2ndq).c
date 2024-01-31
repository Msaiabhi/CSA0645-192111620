#include <stdio.h>
#include <math.h>

// Function to check if a number is Armstrong or not
int isArmstrong(int num) {
    int originalNum = num;
    int n = 0;
    int sum = 0;

    // Count the number of digits
    while (originalNum != 0) {
        originalNum /= 10;
        n++;
    }

    originalNum = num;

    // Calculate the sum of k-th powers of each digit
    while (originalNum != 0) {
        int digit = originalNum % 10;
        sum += pow(digit, n);
        originalNum /= 10;
    }

    // Check if the number is Armstrong
    return (sum == num);
}

int main() {
    // Test cases
    int num1 = 153;
    printf("Input: %d\nOutput: %s\n", num1, isArmstrong(num1) ? "True" : "False");

    int num2 = 419;
    printf("Input: %d\nOutput: %s\n", num2, isArmstrong(num2) ? "True" : "False");

    return 0;
}
