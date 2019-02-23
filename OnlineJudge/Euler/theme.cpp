#include <stdio.h>

int main()
{
    int n, i;
    int a[10] = {0, 10000, 5000, 1000, 500, 100, 50, 10, 5, 1};

    scanf("%d", &n);
    for(i=1 ; i<=9 ; i++)
    {
        if(n == 0)
            break;
        printf("%d ", n/a[i]);
        n %= a[i];
    }
    printf("  ");
    return 0;
}
