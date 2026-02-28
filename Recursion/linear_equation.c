#include <stdio.h>

int n, m, a[20], sum = 0;

void Try(int k)
{
    for (int i = 1; i <= m - n + k; i++)
    {
        if ((sum + i) <= m)
        {
            a[k] = i;
            sum += i;
            if (sum == m && k == n) {
                for (int j = 1; j <= n; j++)
                    printf("%d ", a[j]);
                printf("\n");
            }
            else
                Try(k + 1);
            sum -= i;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    Try(1);
}

