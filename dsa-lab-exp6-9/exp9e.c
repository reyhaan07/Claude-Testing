/* Exp 9(e): Hash Table using Linear Probing */
#include <stdio.h>
#define SIZE 10
int main() {
    int h[SIZE], n, i, k, key, idx;
    for (i = 0; i < SIZE; i++) h[i] = -1;     /* -1 = empty slot */
    printf("Enter number of keys: ");
    scanf("%d", &n);
    printf("Enter %d keys: ", n);
    for (k = 0; k < n; k++) {
        scanf("%d", &key);
        for (i = 0; i < SIZE; i++) {
            idx = (key % SIZE + i) % SIZE;    /* h(k) + i */
            if (h[idx] == -1) { h[idx] = key; break; }
        }
        if (i == SIZE) printf("Table full, %d not inserted\n", key);
    }
    printf("\nHash Table:\n");
    for (i = 0; i < SIZE; i++) {
        if (h[i] == -1) printf("%d : -\n", i);
        else printf("%d : %d\n", i, h[i]);
    }
    printf("Enter key to search: ");
    scanf("%d", &key);
    for (i = 0; i < SIZE; i++) {
        idx = (key % SIZE + i) % SIZE;
        if (h[idx] == key) { printf("Key %d found at index %d\n", key, idx); return 0; }
        if (h[idx] == -1) break;
    }
    printf("Key %d not found\n", key);
    return 0;
}
