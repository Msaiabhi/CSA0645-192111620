#include <stdio.h>

// Function to calculate the sum of digits of a number
int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Function to find the maximum value of the sum of digits between two numbers in an array
int maxSumOfDigitsPair(int nums[], int n) {
    int maxSum = -1;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sumDigitsNum1 = sumOfDigits(nums[i]);
            int sumDigitsNum2 = sumOfDigits(nums[j]);

            if (sumDigitsNum1 == sumDigitsNum2) {
                int product = nums[i] * nums[j];
                if (product > maxSum) {
                    maxSum = product;
                }
            }
        }
    }

    return maxSum;
}

int main() {
    // Test case
    int nums[] = {123, 456, 789, 101, 202};
    int n = sizeof(nums) / sizeof(nums[0]);

    // Find the maximum value of the sum of digits between two numbers
    int result = maxSumOfDigitsPair(nums, n);

    // Print the result
    printf("Maximum value of nums[i] * nums[j] with equal sum of digits: %d\n", result);

    return 0;
}
