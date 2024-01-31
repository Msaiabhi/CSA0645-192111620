#include <stdio.h>
#include <string.h>

// Function to check if a string is a palindrome
int isPalindromeString(char str[]) {
    int length = strlen(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome
}

// Function to check if a number is a palindrome
int isPalindromeNumber(int num) {
    int originalNum = num;
    int reversedNum = 0;

    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    return (originalNum == reversedNum);
}

int main() {
    int choice;

    printf("Select the type of input to check for palindrome:\n");
    printf("1. String\n");
    printf("2. Number\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            char inputString[100];
            printf("Enter a string: ");
            scanf("%s", inputString);

            if (isPalindromeString(inputString)) {
                printf("The entered string is a palindrome.\n");
            } else {
                printf("The entered string is not a palindrome.\n");
            }

            break;
        }
        case 2: {
            int inputNumber;
            printf("Enter a number: ");
            scanf("%d", &inputNumber);

            if (isPalindromeNumber(inputNumber)) {
                printf("The entered number is a palindrome.\n");
            } else {
                printf("The entered number is not a palindrome.\n");
            }

            break;
        }
        default:
            printf("Invalid choice. Please enter 1 or 2.\n");
            return 1; // Exit with an error code
    }

    return 0; // Exit successfully
}

