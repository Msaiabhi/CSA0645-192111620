#include <stdio.h>

// Function to print the subset
void printSubset(int arr[], int n, int subset[], int subsetSize);

// Recursive function to generate subsets
void generateSubsetsUtil(int arr[], int n, int subset[], int subsetSize, int currentIndex);

// Function to generate all possible subsets
void generateSubsets(int arr[], int n);

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

    // Generate and print all possible subsets
    printf("All possible subsets:\n");
    generateSubsets(arr, n);

    return 0;
}

// Function to print the subset
void printSubset(int arr[], int n, int subset[], int subsetSize) {
    printf("{ ");
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", arr[subset[i]]);
    }
    printf("}\n");
}

// Recursive function to generate subsets
void generateSubsetsUtil(int arr[], int n, int subset[], int subsetSize, int currentIndex) {
    // Print the current subset
    printSubset(arr, n, subset, subsetSize);

    // Generate subsets for the remaining elements
    for (int i = currentIndex; i < n; i++) {
        // Include the current element in the subset
        subset[subsetSize] = i;
        subsetSize++;

        // Recursively generate subsets
        generateSubsetsUtil(arr, n, subset, subsetSize, i + 1);

        // Exclude the current element to backtrack and generate other subsets
        subsetSize--;
    }
}

// Function to generate all possible subsets
void generateSubsets(int arr[], int n) {
    int subsetSize = 0; // Size of the current subset
    int subset[n];      // Array to store the current subset

    // Start with an empty subset
    generateSubsetsUtil(arr, n, subset, subsetSize, 0);
}
