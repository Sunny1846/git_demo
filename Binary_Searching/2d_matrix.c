#include <stdio.h>

int u[1000][1000];
int first[1000];

int search_row(int a[], int n, int k) {
    int l = 0, r = n - 1;
    int res = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] <= k) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

int bin_search(int a[], int m, int k) {
    int l = 0, r = m - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == k) return 1;
        if (a[mid] < k) l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            scanf("%d", &u[i][j]);
        first[i] = u[i][0];
    }

    int row = search_row(first, n, q);
    if (row != -1 && bin_search(u[row], m, q))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
