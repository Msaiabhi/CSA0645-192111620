#include <stdio.h>

#define MAX_SIZE 100

// Function to print a subset
void printSubset(int subset[], int size) {
    printf("Subset is (");
    for (int i = 0; i < size; i++) {
        printf("%d", subset[i]);
        if (i < size - 1) {
            printf(",");
        }
    }
    printf(")\n");
}

// Function to find subsets with a given sum using backtracking
void findSubsetsWithSumUtil(int set[], int subset[], int n, int sum, int currentSum, int index, int subsetSize) {
    if (currentSum == sum) {
        printSubset(subset, subsetSize);
        return;
    }

    // Try including the current element in the subset
    if (index < n && currentSum + set[index] <= sum) {
        subset[subsetSize] = set[index];
        findSubsetsWithSumUtil(set, subset, n, sum, currentSum + set[index], index + 1, subsetSize + 1);
    }

    // Exclude the current element and try the next one
    if (index < n) {
        findSubsetsWithSumUtil(set, subset, n, sum, currentSum, index + 1, subsetSize);
    }
}

// Function to find subsets with a given sum
void findSubsetsWithSum(int set[], int n, int sum) {
    int subset[MAX_SIZE];

    findSubsetsWithSumUtil(set, subset, n, sum, 0, 0, 0);
}

int main() {
    // Test cases
    int set1[] = {6, 2, 8, 1, 5};
    int n1 = sizeof(set1) / sizeof(set1[0]);
    int sum1 = 9;

    printf("Input Set(s) = (6, 2, 8, 1, 5) Sum is 9\n");
    printf("Output:\n");
    findSubsetsWithSum(set1, n1, sum1);

    int set2[] = {6, -4, 7, -1, 5, 2, 8, 1};
    int n2 = sizeof(set2) / sizeof(set2[0]);
    int sum2 = 10;

    printf("\nInput Set(s) = (6, -4, 7, -1, 5, 2, 8, 1) Sum is 10\n");
    printf("Output:\n");
    findSubsetsWithSum(set2, n2, sum2);

    return 0;
}
