#include <stdio.h>
#include <stdlib.h>

int a[1000001];
int compare(const void* a, const void* b)
{
    return(*(int*)a - *(int*)b);
}

int main()
{
    int n, q, u = 0;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), compare);
    int l = 0, r = n-1;
    while(1)
    {
        if(l == r)
            break;
        int sum = a[l] + a[r];
        if(sum == q){
            l++;
            u++;
        }
        else if(sum>q)
            r--;
        else
            l++;
    }
    printf("%d", u);
}