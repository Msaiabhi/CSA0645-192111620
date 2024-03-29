#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int weight;
    int value;
    double ratio; // Value-to-weight ratio
};

// Comparison function for sorting items by ratio in descending order
int compareItems(const void *a, const void *b) {
    return ((struct Item *)b)->ratio - ((struct Item *)a)->ratio;
}

// Function to solve the fractional knapsack problem using a greedy approach
void fractionalKnapsack(struct Item items[], int n, int capacity) {
    // Calculate value-to-weight ratio for each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // Sort items by value-to-weight ratio in descending order
    qsort(items, n, sizeof(items[0]), compareItems);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    // Iterate through sorted items and add as much as possible to the knapsack
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            // Take a fractional part of the item
            totalValue += items[i].ratio * remainingCapacity;
            break;
        }
    }

    printf("Maximum value in the knapsack: %.2lf\n", totalValue);
}

int main() {
    int n, capacity;

    // Get user input for the number of items and knapsack capacity
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item *items = (struct Item *)malloc(n * sizeof(struct Item));

    printf("Enter the weight and value for each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    // Get user input for the knapsack capacity
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    // Solve the fractional knapsack problem
    fractionalKnapsack(items, n, capacity);

    free(items);

    return 0;
}
