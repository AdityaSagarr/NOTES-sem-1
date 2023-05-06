#include <stdio.h>
#include <limits.h>
#define MAX 1000

int a[MAX][MAX], n;

// Function to find the vertex with minimum distance value, 
// from the set of vertices not yet included in shortest path tree
int ExtractMin(int S[], int d[]) {
    int i, min = INT_MAX, min_index = -1;
    for (i = 1; i <= n; i++) {
        if (S[i] == 0 && d[i] < min) {
            min = d[i];
            min_index = i;
        }
    }
    return min_index;
}

void Dijkstras(int s) {
    int S[MAX], d[MAX], pred[MAX], u, v, i;
    
    // Initialize distance values, predecessor array and set S to empty
    for (i = 1; i <= n; i++) {
        S[i] = 0;
        d[i] = a[s][i];
        pred[i] = s;
    }
    
    // Mark the source vertex as visited and set its distance to 0
    S[s] = 1;
    d[s] = 0;
    
    // Find shortest path for all vertices
    for (i = 1; i <= n; i++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        u = ExtractMin(S, d);
        // Mark the picked vertex as visited
        S[u] = 1;
        // Update distance value of the adjacent vertices of the picked vertex
        for (v = 1; v <= n; v++) {
            // Update d[v] only if it's not in S, there's an edge from u to v, 
            // and total weight of path from src to v through u is smaller than current value of d[v]
            if (a[u][v] != 0 && S[v] == 0) {
                if (d[u] + a[u][v] < d[v]) {
                    d[v] = d[u] + a[u][v];
                    pred[v] = u;
                }
            }
        }
    }
    
    // Print the shortest distances and paths from the source vertex
    for (i = 1; i <= n; i++) {
        if (i != s) {
            printf("\nDistance of node %d = %d", i, d[i]);
            printf("\nPath = %d", i);
            int j = i;
            do {
                j = pred[j];
                printf(" <- %d", j);
            } while (j != s);
        }
    }
}

int main() {
    int i, j, s;
    // Read input values
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &s);
    // Run Dijkstra's algorithm and print the results
    printf("Shortest distances and paths from source vertex %d:\n", s);
    Dijkstras(s);
    return 0;
}
