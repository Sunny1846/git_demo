#include <stdio.h>

int main()
{
    char s[10000], ch;
    int i = -1;
    while (scanf("%c", &ch) != EOF && ch != '\n')
    {
        if(ch == '(' || ch == '{' || ch == '[')
            s[++i] = ch;
        else 
        {
            if((ch == ')' && s[i] == '(') || 
                (ch == '}' && s[i] == '{') || 
                (ch == ']' && s[i] == '['))
            {
                i--;
            }
            else
            {
                printf("0");
                return 0;
            }
        }    
    }
    if(i == -1)
        printf("1");
    else
        printf("0");
}