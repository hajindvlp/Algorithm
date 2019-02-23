#include <stdio.h>

int a[5] = {0, 25, 10, 5, 1};
int n;

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=4 ; i++)
    {
        printf("%d ", n/a[i]);
        n %= a[i];
    }
    return 0;
}
