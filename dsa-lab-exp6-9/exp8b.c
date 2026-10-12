/* Exp 8(b): Breadth First Search */
#include <stdio.h>
int main() {
    int n, i, j, s, v, a[10][10], vis[10] = {0}, q[10], f = 0, r = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter starting vertex: ");
    scanf("%d", &s);
    q[r++] = s;                               /* enqueue start */
    vis[s] = 1;
    printf("\nBFS traversal: ");
    while (f < r) {
        v = q[f++];                           /* dequeue */
        printf("%d ", v);
        for (i = 0; i < n; i++)
            if (a[v][i] && !vis[i]) { q[r++] = i; vis[i] = 1; }
    }
    printf("\n");
    return 0;
}
