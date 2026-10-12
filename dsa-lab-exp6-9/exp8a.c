/* Exp 8(a): Depth First Search */
#include <stdio.h>
int a[10][10], vis[10], n;
void dfs(int v) {
    int i;
    vis[v] = 1;
    printf("%d ", v);
    for (i = 0; i < n; i++)
        if (a[v][i] && !vis[i])
            dfs(i);
}
int main() {
    int i, j, s;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter starting vertex: ");
    scanf("%d", &s);
    printf("\nDFS traversal: ");
    dfs(s);
    printf("\n");
    return 0;
}
