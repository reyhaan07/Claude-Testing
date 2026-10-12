/* Exp 6(b): Floyd-Warshall Algorithm */
#include <stdio.h>
int main() {
    int n, i, j, k, d[10][10];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix (999 = no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &d[i][j]);
    for (k = 0; k < n; k++)                   /* via every vertex k */
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
    printf("\nAll-pairs shortest path matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d\t", d[i][j]);
        printf("\n");
    }
    return 0;
}
