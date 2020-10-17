#include <stdio.h>

int c[7]={0, 1, 5, 10, 25, 50, 100};
int d[100000001], n;

int main()
{
    int i, j;

    scanf("%d", &n);

    d[0] = 1;

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=6 ; j++)
            if(i-c[j]>=0)
                d[i]+=d[i-c[j]];

    for(i=1 ; i<=n ; i++)
        printf("%d ", d[i]);
    return 0;

    printf("%d", d[n]);
    return 0;
}
