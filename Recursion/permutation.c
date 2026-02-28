#include <stdio.h>

int n, a[20], mark[20];

int check(int u)
{
    return mark[u] == 0;
}

void Try(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (check(i)) {
            a[x] = i;
            mark[i] = 1;
            if (x == n) {
                for (int j = 1; j <= n; j++)
                    printf("%d ", a[j]);
                printf("\n");
            }
            else
                Try(x + 1);
            mark[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    Try(1);
}