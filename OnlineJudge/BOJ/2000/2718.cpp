#include <stdio.h>
#define INF 2147483647

int d[1001], t, a;

int main()
{
    int i;

    d[0] = 1;
    d[1] = 1;
    d[2] = 5;
    d[3] = 11;
    for(i=4 ; i<=1000 ; i++)
    {
        d[i] = d[i-1]+5*d[i-2]+d[i-3]+d[i-4];
        if(d[i]<0 || d[i]>INF)
            break;
    }

    scanf("%d", &t);
    for(i=1 ; i<=t ; i++)
        scanf("%d", &a), printf("%d\n", d[a]);
}
