/* Exp 8(c): Topological Sorting (Kahn's / indegree method) */
#include <stdio.h>
int main() {
    int n, i, j, k, a[10][10], in[10] = {0}, vis[10] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (directed):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            in[j] += a[i][j];                 /* indegree of column j */
        }
    printf("\nTopological order: ");
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++)               /* find vertex with indegree 0 */
            if (in[i] == 0 && !vis[i]) break;
        if (i == n) { printf("\nCycle exists! Not a DAG."); break; }
        vis[i] = 1;
        printf("%d ", i);
        for (j = 0; j < n; j++)               /* remove its outgoing edges */
            if (a[i][j]) in[j]--;
    }
    printf("\n");
    return 0;
}
