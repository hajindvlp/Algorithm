#include <stdio.h>

unsigned long long int d[101];
int n, m;

int main()
{
    int i, j;

    scanf("%d %d", &n, &m);

    d[0] = 1;
    for(i=1 ; i<=n ; i++)
        for(j=i-m ; j<i ; j++)
            if(j>=0)
                d[i]+=d[j];

    for(i=1 ; i<=n ; i++)
        printf("%llu ", d[i]);
    return 0;
}
