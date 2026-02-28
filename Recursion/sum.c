// #include <stdio.h>

// int n, b, a[50], count = 0, sum = 0;

// void Try(int k)
// {
//     for (int i = k; i < n; i++)
//     {
//         sum += a[i];
//         if (sum == b)
//             count++;
//         else if (sum < b)
//             Try(i + 1);
//         sum -= a[i];
//     }
// }

// int main()
// {
//     scanf("%d %d", &n, &b);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &a[i]);
//     Try(0);
//     printf("%d", count);
// }

#include <stdio.h>

int n, b;
int a[50];
int count = 0;

void backtrack(int index, int sum)
{
    if (sum == b)
    {
        count++;
        return; // Found a valid subset
    }
    if (sum > b || index == n)
        return; // Invalid or out of bounds

    // Option 1: include a[index]
    backtrack(index + 1, sum + a[index]);

    // Option 2: skip a[index]
    backtrack(index + 1, sum);
}

int main()
{
    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    backtrack(0, 0);

    printf("%d\n", count);
    return 0;
}
