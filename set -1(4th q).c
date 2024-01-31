#include <stdio.h>

// Function to compute binomial coefficient using dynamic programming
int binomialCoefficient(int n, int k) {
    if (k < 0 || k > n) {
        return 0; // Condition: n choose k is 0 for k < 0 or k > n
    }

    int dp[n + 1][k + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1; // Condition: n choose 0 = n choose n = 1
            } else if (i > j) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[n][k];
}

int main() {
    // Test case
    int n = 11;
    int k = 5;

    // Compute binomial coefficient
    int result = binomialCoefficient(n - 8, k);

    // Print the result
    printf("%dC%d = %d\n", n - 8, k, result);

    return 0;
}
