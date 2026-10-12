/* Exp 9(c): Quick Sort */
#include <stdio.h>
void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
int partition(int a[], int lo, int hi) {
    int p = a[hi], i = lo - 1, j;             /* last element = pivot */
    for (j = lo; j < hi; j++)
        if (a[j] < p) swap(&a[++i], &a[j]);
    swap(&a[i + 1], &a[hi]);
    return i + 1;
}
void quick(int a[], int lo, int hi) {
    if (lo < hi) {
        int p = partition(a, lo, hi);
        quick(a, lo, p - 1);
        quick(a, p + 1, hi);
    }
}
int main() {
    int n, i, a[20];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quick(a, 0, n - 1);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
