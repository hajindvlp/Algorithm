#include <stdio.h>
#define max(x, y) ((x)>(y)) ? (x) : (y)

int n, w, d[101][10001];
int a[101][3];

int main()
{
    int i, j;
    int x, y;

    scanf("%d %d", &n, &w);
    for(i=1 ; i<=n ; i++)
        scanf("%d %d", &a[i][2], &a[i][1]);

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=w ; j++)
        {
            if(j>=a[i][2]) d[i][j] = max(d[i-1][j], d[i-1][j-a[i][2]]+a[i][1]);
            else d[i][j] = d[i-1][j];
        }

    printf("%d", d[n][w]);
    return 0;
}
