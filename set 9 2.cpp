#include <stdio.h>
#include <limits.h>

// Function to find the optimal binary search tree cost
int optimalBST(int keys[], int freq[], int n) {
    int cost[n][n];

    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        freq[r];

                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int n;

    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n];
    int freq[n];

    printf("Enter %d keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    printf("Enter frequencies for %d keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    int result = optimalBST(keys, freq, n);

    printf("The cost of the optimal binary search tree is: %d\n", result);

    return 0;
}

