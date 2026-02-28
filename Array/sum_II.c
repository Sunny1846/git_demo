#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    return(*(int*)a - *(int*)b);
}

int main()
{
    int a[6] = {-1, 0, 1, 2, -1, -4};
    qsort(a, 6, sizeof(int), compare);
    for(int i = 0; i < 6 - 2; i++)
    {
        if(a[i] == a[i-1])
            continue;
        int l = i+1, r = 5;
        while(l < r)
        {
            int threesum = a[i] + a[l] + a[r];
            if(threesum>0)
                r--;
            else if(threesum<0)
                l++;
            else {
                printf("%d %d %d\n", a[i], a[l], a[r]);
                l++;
            }
        }
    }    
}