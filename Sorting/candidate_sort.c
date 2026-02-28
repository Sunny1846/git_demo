#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
    char id[10];
    int grade;
} student;

student* a[100000];

int compare_grade(const void* a, const void* b)
{
    student* x = *(student**)a;
    student* y = *(student**)b;
    int u = x->grade;
    int v = y->grade;
    if(u>v)
        return -1;
    if(u<v)
        return 1;
    return 0;
}

int main()
{
    int n = 0;
    while(1)
    {
        a[n] = (student*)malloc(sizeof(student));
        scanf("%s %d", a[n]->id, &a[n]->grade);
        if(strcmp(a[n]->id, "#") == 0)
            break;
        n++;
    }

    qsort(a, n, sizeof(student*), compare_grade);

    for(int i = 0; i < n; i++)
    {
        printf("%s %d", a[i]->id, a[i]->grade);
        printf("\n");
    }
}
