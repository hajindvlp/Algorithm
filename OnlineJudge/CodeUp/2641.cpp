#include <stdio.h>

int d[3][16];
int n;

int main()
{
    int i;

    scanf("%d", &n);
    d[1][0] = d[2][0] = 1;
    for(i=1 ; i<=n ; i++)
    {
        if(i == 1) d[2][0] = d[1][i] = d[1][i-1];
        else if(i == 2) d[2][i] += d[2][i-1]+d[2][i-2], d[1][i] += d[1][i-1]+d[1][i-2];
        else d[2][i] += d[2][i-1]+d[2][i-2]+d[2][i-3]
    }
}
