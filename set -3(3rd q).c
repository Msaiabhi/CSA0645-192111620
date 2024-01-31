#include <stdio.h>
#include <limits.h>

// Structure to hold both minimum and maximum values
struct MinMax {
    int min;
    int max;
};

// Function to find minimum and maximum values in a list using divide-and-conquer
struct MinMax findMinMax(int arr[], int low, int high) {
    struct MinMax result, left, right;
    int mid;

    // Base case: Only one element in the array
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    // Base case: Two elements in the array
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            result.min = arr[high];
            result.max = arr[low];
        } else {
            result.min = arr[low];
            result.max = arr[high];
        }
        return result;
    }

    // Divide the array into two halves
    mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    // Combine the results from the two halves
    if (left.min < right.min) {
        result.min = left.min;
    } else {
        result.min = right.min;
    }

    if (left.max > right.max) {
        result.max = left.max;
    } else {
        result.max = right.max;
    }

    return result;
}

int main() {
    // Test Case A
    int arrA[] = {23, 45, 6, 8, -9, 44, 7, 8};
    int nA = sizeof(arrA) / sizeof(arrA[0]);
    struct MinMax resultA = findMinMax(arrA, 0, nA - 1);
    printf("Test Case A: Min Val = %d, Max Value = %d\n", resultA.min, resultA.max);

    // Test Case B
    int arrB[] = {8, -5, 7, 11, 22, 16};
    int nB = sizeof(arrB) / sizeof(arrB[0]);
    struct MinMax resultB = findMinMax(arrB, 0, nB - 1);
    printf("Test Case B: Min Val = %d, Max Value = %d\n", resultB.min, resultB.max);

    // Test Case C
    int arrC[] = {45, 'Y', 9, 8, 4, 7, 11, 22, 16};
    int nC = sizeof(arrC) / sizeof(arrC[0]);
    struct MinMax resultC = findMinMax(arrC, 0, nC - 1);

    if (resultC.min == INT_MAX && resultC.max == INT_MIN) {
        printf("Test Case C: Illegal input\n");
    } else {
        printf("Test Case C: Min Val = %d, Max Value = %d\n", resultC.min, resultC.max);
    }

    return 0;
}
