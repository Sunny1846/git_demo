#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mark_s[30] = {0};
int mark_t[30] = {0};

int compare(const void* a, const void* b)
{
    return(*(char*)a - *(char*)b);
}

int main()
{
    char s[10] = "hell";
    char t[10] = "ohell";

    //sort
    qsort(s, strlen(s), sizeof(char), compare);
    qsort(t, strlen(t), sizeof(char), compare);
    if(strcmp(s, t) == 0)
        printf("True");
    else    printf("False");

    //hash
    for(int i = 0, e = strlen(s); i < e; i++)
        mark_s[s[i] - 'a']++;
    for(int i = 0, e = strlen(t); i < e; i++)
        mark_t[t[i] - 'a']++;
    for(int i = 0; i < 27; i++)
        if(mark_s[i] != mark_t[i])
        {
            printf("False");
            return 0;
        }
    printf("True");
}