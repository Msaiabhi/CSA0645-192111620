#include <stdio.h>

// Function to check if a number is palindrome
int isPalindrome(int num) {
    int originalNum = num;
    int reverseNum = 0, remainder;

    while (num > 0) {
        remainder = num % 10;
        reverseNum = reverseNum * 10 + remainder;
        num /= 10;
    }

    // Check if the original number is equal to its reverse
    return (originalNum == reverseNum);
}

int main() {
    int number;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Check if the number is palindrome
    if (isPalindrome(number)) {
        printf("True");
    } else {
        printf("False");
    }

    return 0;
}

