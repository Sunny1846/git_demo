#include <stdio.h>

int sudoku[9][9];
int markR[9][10] = {0};
int markC[9][10] = {0};
int markS[3][3][10] = {0};
int count = 0;

int check(int v, int r, int c)
{
    if (markR[r][v])
        return 0;
    if (markC[c][v])
        return 0;
    if (markS[r/3][c/3][v])
        return 0;
    return 1;
}

void Try(int r, int c)
{
    if (sudoku[r][c] > 0)
    {
        if (r == 8 && c == 8)
            count++;
        else
        {
            if (c == 8)
                Try(r + 1, 0);
            else 
                Try(r, c + 1);
        }
    }
    else
    {
        for (int v = 1; v <= 9; v++)
        {
            if (check(v, r, c))
            {
                sudoku[r][c] = v;
                markR[r][v] = 1;
                markC[c][v] = 1;
                markS[r/3][c/3][v] = 1;
                if (r == 8 && c == 8)
                    count++;
                else 
                {
                    if (c == 8)
                        Try(r + 1, 0);
                    else 
                        Try(r, c + 1);
                }
                markR[r][v] = 0;
                markC[c][v] = 0;
                markS[r/3][c/3][v] = 0;
                sudoku[r][c] = 0;
            }
        }
    }
}

int main()
{
    for (int r = 0; r < 9; r++)
        for (int c = 0; c < 9; c++)
        {
            int v;
            scanf("%d", &v);
            sudoku[r][c] = v;
            if (v != 0)
            {
                markR[r][v] = 1;
                markC[c][v] = 1;
                markS[r/3][c/3][v] = 1;
            }
        }
    Try(0, 0);
    printf("%d", count);
    return 0;
}
