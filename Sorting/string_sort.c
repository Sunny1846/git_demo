#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* s[100000];

void merge(char** a, int p, int r, int q) {
    int x = r - p + 1;
    int y = q - r;
    char* a_1[100000];
    char* a_2[100000];

    for (int i = 0; i < x; i++)
        a_1[i] = a[p + i];
    for (int i = 0; i < y; i++)
        a_2[i] = a[r + 1 + i];

    int u = 0, v = 0, z = p;

    while (u < x && v < y) {
        if (strcmp(a_1[u], a_2[v]) <= 0)
        {
            a[z] = a_1[u];
            u++;
            z++;
        }
        else
        {
            a[z] = a_2[v];
            v++;
            z++;
        }
    }
    while (u < x)
    {
        a[z] = a_1[u];
        u++;
        z++;
    }
    while (v < y)
    {
        a[z] = a_2[v];
        v++;
        z++;
    }
}

void merge_sort(char** a, int p, int q)
{
    if(p < q)
    {
        int r = p + (q-p)/2;
        merge_sort(a, p, r);
        merge_sort(a, r+1, q);
        merge(a, p, r, q);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        s[i] = (char*)malloc(sizeof(s));
        scanf("%s", s[i]);
    }

    merge_sort(s, 0, n-1);

    for(int i = 0; i < n; i++)
        printf("%s\n", s[i]);
}
