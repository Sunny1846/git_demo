#include <stdio.h>
#include <string.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        char s[200];
        int h = 0;
        scanf("%s", s);
        int l = strlen(s);
        for(int j = 0; j < l; j++){
            h = (h*256+s[j])%m;
        }
        printf("%d\n", h);
    }
}