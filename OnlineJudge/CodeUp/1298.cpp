#include <stdio.h>

int main()
{
    int x, y;
    int i, j;

    scanf("%d %d", &x, &y);
    int s = (x>y)?y:x;
    int e = (x>y)?x:y;

    for(i=s ; i<=e ; i++)
        for(j=1 ; j<=9 ; j++)
            printf("%d*%d=%d\n", i, j, i*j);
    return 0;
}
