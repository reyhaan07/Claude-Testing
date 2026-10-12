/* Exp 7(a): Kruskal's Algorithm */
#include <stdio.h>
int parent[10];
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}
int main() {
    int n, i, j, a = 0, b = 0, u, v, min, ne = 1, total = 0, cost[10][10];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix (0 = no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) cost[i][j] = 999;
        }
    for (i = 0; i < n; i++)
        parent[i] = i;
    printf("\nEdges in MST:\n");
    while (ne < n) {
        min = 999;
        for (i = 0; i < n; i++)               /* smallest remaining edge */
            for (j = 0; j < n; j++)
                if (cost[i][j] < min) { min = cost[i][j]; a = i; b = j; }
        if (min == 999) break;
        u = find(a);
        v = find(b);
        if (u != v) {                         /* no cycle -> accept */
            printf("Edge %d: (%d - %d) cost = %d\n", ne++, a, b, min);
            total += min;
            parent[v] = u;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("Minimum cost = %d\n", total);
    return 0;
}
