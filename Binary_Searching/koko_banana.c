#include <stdio.h>
#include <math.h>

int main()
{
    int piles[4] = {25,10,23,4};
    int h = 4, k = 25;
    int left = 1, right = 25;
    while(left <= right)
    {
        int hour = 0;
        int mid = (left+right)/2;
        for(int i = 0; i < 4; i++)
            hour += ceil(piles[i]*1.0/mid);
        if(hour <= h){
            k = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    printf("%d", k);
}