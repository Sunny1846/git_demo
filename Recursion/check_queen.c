#include <stdio.h>

int n, count = 0;
int pos_in_row[20] = {0};
int markCol[20] = {0};
int markDiagonal1[40] = {0};
int markDiagonal2[40] = {0};

int check(int r, int c)
{
    if (markCol[c])
        return 0;
    if (markDiagonal1[n + c - r])
        return 0;
    if (markDiagonal2[c + r])
        return 0;
    return 1;
}

void Try(int r)
{
    if (pos_in_row[r])
    {
        if (r == n)
            count++;
        else
            Try(r + 1);
    }
    else
    {
        for (int c = 1; c <= n; c++)
        {
            if (check(r, c))
            {
                pos_in_row[r] = c;
                markCol[c] = 1;
                markDiagonal1[n + c - r] = 1;
                markDiagonal2[c + r] = 1;
                if (r == n)
                    count++;
                else
                    Try(r + 1);
                pos_in_row[r] = 0;
                markCol[c] = 0;
                markDiagonal1[n + c - r] = 0;
                markDiagonal2[c + r] = 0;

            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int r = 1; r <= n; r++)
        for (int c = 1; c <= n; c++)
        {
            int e;
            scanf("%d", &e);
            if (e == 1)
            {
                pos_in_row[r] = c;
                markCol[c] = 1;
                markDiagonal1[n + c - r] = 1;
                markDiagonal2[c + r] = 1;
            }
        }
    Try(1);
    printf("%d", count);
    return 0;
}