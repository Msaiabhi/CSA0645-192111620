#include <stdio.h>
#include <limits.h>

// Function to find the M-th maximum and N-th minimum numbers in an array
void findMthMaxNthMin(int arr[], int size, int M, int N) {
    // Check for illegal input
    if (M >= size || N >= size || M < 0 || N < 0 || M == N) {
        printf("(illegal input)\n");
        return;
    }

    // Sort the array in ascending order
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if the current element is greater than the next element
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Find the M-th maximum and N-th minimum numbers
    int MthMax = arr[size - M - 1];
    int NthMin = arr[N];

    // Calculate the sum and difference
    int sum = MthMax + NthMin;
    int diff = MthMax - NthMin;

    // Print the results
    printf("%d\n", sum);
    printf("%d\n", diff);
}

int main() {
    // Test cases
    int arr1[] = {16, 16, 16, 16, 16};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    findMthMaxNthMin(arr1, size1, 0, 1);

    int arr2[] = {0, 0, 0, 0};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    findMthMaxNthMin(arr2, size2, 1, 2);

    int arr3[] = {-12, -78, -35, -42, 85};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    findMthMaxNthMin(arr3, size3, 3, 3);

    int arr4[] = {15, 19, 34, 56, 12};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    findMthMaxNthMin(arr4, size4, 6, -3);

    int arr5[] = {85, 45, 65, 75, 95};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    findMthMaxNthMin(arr5, size5, 5, 2);

    return 0;
}
