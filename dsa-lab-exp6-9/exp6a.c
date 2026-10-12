/* Exp 6(a): Dijkstra's Algorithm */
#include <stdio.h>
#define INF 999
int main() {
    int n, i, v, u = 0, src, min, cost[10][10], dist[10], vis[10] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix (999 = no edge):\n");
    for (i = 0; i < n; i++)
        for (v = 0; v < n; v++)
            scanf("%d", &cost[i][v]);
    printf("Enter source vertex: ");
    scanf("%d", &src);
    for (i = 0; i < n; i++)
        dist[i] = cost[src][i];
    dist[src] = 0;
    vis[src] = 1;
    for (i = 1; i < n; i++) {
        min = INF;
        for (v = 0; v < n; v++)               /* pick nearest unvisited */
            if (!vis[v] && dist[v] < min) { min = dist[v]; u = v; }
        if (min == INF) break;
        vis[u] = 1;
        for (v = 0; v < n; v++)               /* relax neighbours of u */
            if (!vis[v] && dist[u] + cost[u][v] < dist[v])
                dist[v] = dist[u] + cost[u][v];
    }
    printf("\nShortest distances from vertex %d:\n", src);
    for (i = 0; i < n; i++)
        printf("Vertex %d : %d\n", i, dist[i]);
    return 0;
}
