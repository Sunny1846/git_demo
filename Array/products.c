#include <stdio.h>

int main(){
    int a[4] = {1,2,4,6};
    int p[4], post = 1;
    for(int i = 0; i < 4; i++){
        p[i] = 1;
        if(i)
            p[i] = p[i-1]*a[i-1];
    }
    for(int i = 3; i >= 0; i--){
        if(i!=3)
            p[i]*=post;
        post*=a[i];
    }
    for(int i = 0; i < 4; i++)
        printf("%d ", p[i]);
}