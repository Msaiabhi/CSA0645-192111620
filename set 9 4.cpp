#include <stdio.h>

int main() {
    int n;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Please enter at least two elements.\n");
        return 1; // Indicates an error
    }

    int arr[n];

    // Input the elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the first and second minimum values
    int min1, min2;
    min1 = min2 = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
    }

    // Print the results
    printf("The first minimum value is: %d\n", min1);
    printf("The second minimum value is: %d\n", min2);

    return 0;
}

