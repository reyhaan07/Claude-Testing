/* Exp 7(b): Prim's Algorithm */
#include <stdio.h>
int main() {
    int n, i, j, e, a = 0, b = 0, min, total = 0, cost[10][10], vis[10] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix (0 = no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) cost[i][j] = 999;
        }
    vis[0] = 1;                               /* start from vertex 0 */
    printf("\nEdges in MST:\n");
    for (e = 1; e < n; e++) {
        min = 999;
        for (i = 0; i < n; i++)               /* cheapest edge tree -> outside */
            if (vis[i])
                for (j = 0; j < n; j++)
                    if (!vis[j] && cost[i][j] < min) { min = cost[i][j]; a = i; b = j; }
        if (min == 999) break;
        vis[b] = 1;
        printf("Edge %d: (%d - %d) cost = %d\n", e, a, b, min);
        total += min;
    }
    printf("Minimum cost = %d\n", total);
    return 0;
}
