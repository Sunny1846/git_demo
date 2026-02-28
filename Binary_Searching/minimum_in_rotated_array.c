#include <stdio.h>

int a[10];

int Search_min(int left, int right){
    int mid;
    while(left<right){
        mid = left + (right-left)/2;
        if(a[left] > a[mid])
            right = mid+1;
        else
            left = mid+1;
    }
    return a[mid];
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", Search_min(0, n-1));
}