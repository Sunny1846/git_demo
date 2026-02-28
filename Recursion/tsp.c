#include <stdio.h>

int n, mark[20] = {0};
int d[20][20];
int city[20];
int f = 0, f_min = 1000000;
int cm = 10000000;

void Try(int k)
{
    for (int v = 2; v <= n; v++)
    {
        if (mark[v] == 0)
        {
            city[k] = v;
            f += d[city[k - 1]][v];
            mark[v] = 1;
            if (k == n)
            {
                if (f_min > f + d[v][1])
                    f_min = f + d[v][1];
            }
            else {
                if ((f + cm * (n - k + 1)) < f_min)
                    Try(k + 1);
            }
            f -= d[city[k - 1]][v];
            mark[v] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &d[i][j]);
            if (cm > d[i][j] && i != j)
                cm = d[i][j];
        }
    city[1] = 1;
    mark[1] = 1;
    Try(2);
    printf("%d", f_min);
}