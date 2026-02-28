#include <stdio.h>
#include <string.h>
#define N 10

int n, m;
int count;
int a[N];

void find_m(int k, int m){
    for(int i = k; i < n; i++){
        if(m-a[i] == 0)
            count++;
        else if(m-a[i] > 0)
            find_m(i, m-a[i]);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    count = 0;
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    find_m(0, m);
    printf("%d", count);
}