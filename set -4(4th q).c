#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i + 1;  // Return the position (1-indexed)
        }
    }
    return -1;  // Return -1 if key is not found
}

int main() {
    // Test case A
    int arrA[] = {56, 89, 7, 13, 75, 23, 8, 12};
    int sizeA = sizeof(arrA) / sizeof(arrA[0]);
    int keyA = 75;

    int resultA = linearSearch(arrA, sizeA, keyA);

    if (resultA != -1) {
        printf("Test case A: Element found at position %d\n", resultA);
    } else {
        printf("Test case A: Element not found\n");
    }

    // Test case B
    float arrB[] = {59.45, 23.45, 0, 44, 2};
    int sizeB = sizeof(arrB) / sizeof(arrB[0]);
    float keyB = 0;

    int resultB = linearSearch((int*)arrB, sizeB, *(int*)&keyB);

    if (resultB != -1) {
        printf("Test case B: Element found at position %d\n", resultB);
    } else {
        printf("Test case B: Element not found\n");
    }

    // Test case C
    double arrC[] = {45.67, 36.34, 2, 100};
    int sizeC = sizeof(arrC) / sizeof(arrC[0]);
    double keyC = 90;

    int resultC = linearSearch((int*)arrC, sizeC, *(int*)&keyC);

    if (resultC != -1) {
        printf("Test case C: Element found at position %d\n", resultC);
    } else {
        printf("Test case C: Element not found\n");
    }

    return 0;
}
