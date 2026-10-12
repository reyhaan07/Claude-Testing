/* Exp 9(d): Merge Sort */
#include <stdio.h>
void merge(int a[], int lo, int mid, int hi) {
    int t[20], i = lo, j = mid + 1, k = 0;
    while (i <= mid && j <= hi)
        t[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while (i <= mid) t[k++] = a[i++];
    while (j <= hi)  t[k++] = a[j++];
    for (i = lo, k = 0; i <= hi; i++, k++)
        a[i] = t[k];
}
void msort(int a[], int lo, int hi) {
    if (lo < hi) {
        int mid = (lo + hi) / 2;
        msort(a, lo, mid);
        msort(a, mid + 1, hi);
        merge(a, lo, mid, hi);
    }
}
int main() {
    int n, i, a[20];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    msort(a, 0, n - 1);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
