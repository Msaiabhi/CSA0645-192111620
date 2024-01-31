#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverseString(char str[]) {
    int length = strlen(str);

    for (int i = 0, j = length - 1; i < j; i++, j--) {
        // Swap characters at positions i and j
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char inputString[100];

    // Get input string from the user
    printf("Enter a string: ");
    scanf("%s", inputString);

    // Reverse the string
    reverseString(inputString);

    // Display the reversed string
    printf("Reversed string: %s\n", inputString);

    return 0; // Exit successfully
}

