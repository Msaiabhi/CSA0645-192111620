#include <stdio.h>

// Function to perform binary search in a sorted array
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found, return its index
        } else if (arr[mid] < target) {
            left = mid + 1; // Target is in the right half
        } else {
            right = mid - 1; // Target is in the left half
        }
    }

    return -1; // Target not found
}

int main() {
    // Test case
    int arr[] = {45, 4, 23, -11, 20, 5, 10, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    // Perform binary search
    int result = binarySearch(arr, size, target);

    // Print the result
    if (result != -1) {
        printf("Target %d found at index %d\n", target, result);
    } else {
        printf("Target %d not found\n", target);
    }

    return 0;
}
