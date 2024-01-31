#include <stdio.h>

// Function to find the reverse of a given number
int reverseNumber(int num) {
    int reversedNum = 0;

    while (num != 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    return reversedNum;
}

int main() {
    // Test cases
    int num1 = 1234;
    printf("%d %d\n", num1, reverseNumber(num1));

    int num2 = 45434;
    printf("%d %d\n", num2, reverseNumber(num2));

    int num3 = 4321;
    printf("%d %d\n", num3, reverseNumber(num3));

    int num4 = -49876;
    printf("%d %d\n", num4, reverseNumber(num4));

    return 0;
}
