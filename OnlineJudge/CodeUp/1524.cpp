#include <stdio.h>

int a[20][20], sx, sy, sum;
int dy[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dx[8]={0, 1, 1, 1, 0, -1, -1, -1};

int main()
{
    int i, j;

    for(i=1 ; i<=9 ; i++)
        for(j=1 ; j<=9 ; j++)
            scanf("%d", &a[i][j]);
    scanf("%d %d", &sy, &sx);

    for(i=0 ; i<8 ; i++)
        sum+=a[sy+dy[i]][sx+dx[i]];

    if(a[sy][sx] == 1)
        printf("-1");
    else
        printf("%d", sum);
    return 0;
}
