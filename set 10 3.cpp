#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int n; // Number of vertices in the graph
int graph[MAX][MAX]; // Adjacency matrix representing the graph
int path[MAX]; // Array to store the Hamiltonian Circuit

// Function to check if a vertex can be added to the Hamiltonian Circuit
bool isSafe(int v, int pos, int path[]) {
    // Check if the vertex is adjacent to the last added vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has not already been included
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Function to find Hamiltonian Circuit using backtracking
bool hamiltonianCircuitUtil(int path[], int pos) {
    // If all vertices are included in the Hamiltonian Circuit
    if (pos == n) {
        // Check if the last vertex is adjacent to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    // Try different vertices as the next candidate in the Hamiltonian Circuit
    for (int v = 1; v < n; v++) {
        if (isSafe(v, pos, path)) {
            path[pos] = v;

            // Recur to construct the rest of the Hamiltonian Circuit
            if (hamiltonianCircuitUtil(path, pos + 1))
                return true;

            // If adding the vertex v doesn't lead to a solution, then remove it
            path[pos] = -1;
        }
    }

    return false;
}

// Function to find and print Hamiltonian Circuit
void hamiltonianCircuit() {
    int path[MAX];

    // Initialize path array with -1
    for (int i = 0; i < n; i++)
        path[i] = -1;

    // Start from the first vertex (0 as the starting point)
    path[0] = 0;

    if (hamiltonianCircuitUtil(path, 1)) {
        printf("Hamiltonian Circuit exists:\n");
        for (int i = 0; i < n; i++)
            printf("%d ", path[i]);
        printf("%d", path[0]); // Complete the circuit
        printf("\n");
    } else {
        printf("Hamiltonian Circuit does not exist.\n");
    }
}

int main() {
    // Get the number of vertices from the user
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Get the adjacency matrix representing the graph from the user
    printf("Enter the adjacency matrix (1 for connected, 0 for not connected):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    hamiltonianCircuit();

    return 0;
}
