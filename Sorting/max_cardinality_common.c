#include <stdio.h>
#include <stdlib.h>

const int a = 100000;


int compare(const void* a, const void* b)
{
    int x = *(int*)a;
    int y = *(int*)b;
    return (x-y);
}

int main()
{
    int n, m;
    int an[a], am[a];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &an[i]);
    for(int i = 0; i < m; i++)
        scanf("%d", &am[i]);
    qsort(an, n, sizeof(int), compare);
    qsort(am, m, sizeof(int), compare);
    int u = 0, v = 0, z = 0;
    while(u < n && v < m)
    {
        if(an[u] < am[v])
            u++;
        if(an[u] > am[v])
            v++;
        if(an[u] == am[v])
        {
            u++;
            v++;
            z++;
        }
    }
    printf("%d", z);
}