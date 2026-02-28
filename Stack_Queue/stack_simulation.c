#include <stdio.h>
#include <string.h>

#define MAX 1000

int main()
{
    int stack[MAX], min[MAX], i = 0;
    min[0] = 9999;
    char s[20];
    while(1)
    {
        scanf("%s", s);
        if(strcmp(s, "#") == 0)
            break;
        else if(strcmp(s, "push") == 0) {
            scanf("%d", &stack[i]);
            if(i == 0)
                min[i] = stack[i];
            else if(stack[i] < min[i-1])
                min[i] = stack[i];
            else 
                min[i] = min[i-1];
            i++;
        }
        else if(strcmp(s, "pop") == 0)
            i--;
        else
            printf("%d\n", min[i-1]);
    }    
}