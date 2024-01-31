#include <stdio.h>

// Function to check if a number is perfect
int isPerfect(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return (sum == num);
}

int main() {
    int n;

    // Get the value of n from the user
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer for n.\n");
        return 1; // Exit with an error code
    }

    printf("First %d perfect numbers:\n", n);

    int count = 0;
    int num = 1;

    // Keep finding perfect numbers until we print the first n
    while (count < n) {
        if (isPerfect(num)) {
            printf("%d\n", num);
            count++;
        }
        num++;
    }

    return 0; // Exit successfully
}

