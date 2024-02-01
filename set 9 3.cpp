#include <stdio.h>

// Function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to generate permutations of an array
void generatePermutations(int arr[], int start, int end) {
    if (start == end) {
        // Print the current permutation
        for (int i = 0; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        // Recursively generate permutations
        for (int i = start; i <= end; i++) {
            // Swap the current element with the element at index 'i'
            swap(&arr[start], &arr[i]);
            
            // Recursively generate permutations for the remaining elements
            generatePermutations(arr, start + 1, end);
            
            // Backtrack - undo the swap for the next iteration
            swap(&arr[start], &arr[i]);
        }
    }
}

int main() {
    int n;

    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Get array elements from the user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Generate and print permutations
    printf("Permutations:\n");
    generatePermutations(arr, 0, n - 1);

    return 0;
}
