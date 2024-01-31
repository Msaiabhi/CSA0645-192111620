#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays using Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftArr = (int *)malloc(n1 * sizeof(int));
    int *rightArr = (int *)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays leftArr[] and rightArr[]
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] >= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if there are any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if there are any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Free the allocated memory
    free(leftArr);
    free(rightArr);
}

// Recursive function to perform Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    // Input arrays
    int nums1[] = {3, 8, 1, 9};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);

    int nums2[] = {4, -2, 0, 7};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);

    // Merge both arrays into a single array
    int mergedSize = n1 + n2;
    int *mergedArray = (int *)malloc(mergedSize * sizeof(int));

    for (int i = 0; i < n1; i++)
        mergedArray[i] = nums1[i];
    for (int j = 0; j < n2; j++)
        mergedArray[n1 + j] = nums2[j];

    // Perform Merge Sort on the merged array
    mergeSort(mergedArray, 0, mergedSize - 1);

    // Print the sorted merged array
    printf("Merged and Sorted Array: ");
    printArray(mergedArray, mergedSize);

    // Free the allocated memory
    free(mergedArray);

    return 0;
}
