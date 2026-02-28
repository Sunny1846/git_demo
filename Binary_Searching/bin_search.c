#include <stdio.h>

int a[10001];

int bin_search(int left, int right, int k)
{
    if(a[left] == k)
        return left;
    if(left <= right) {
        int mid = left + (right - left)/2;
        if(a[mid] == k)
            return mid;
        else if(a[mid] > k)
            return bin_search(left, mid-1, k);
        else
            return bin_search(mid+1, right, k);
    }
    return -1;
}

int main()
{
    for(int i = 0; i < 10; i++)
        a[i] = i;
    printf("%d", bin_search(0, 9, 99));
}