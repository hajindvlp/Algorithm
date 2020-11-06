#include <stdio.h>

int n, m, a[16][16], visit[16][16], path[16][16];
int dy[4]={0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

bool pro()
{
    int i, j, sx, sy, ty, tx;
    char tmp[16];

    for(i=1 ; i<=15 ; i++)
        for(j=1 ; j<=15 ; j++)
            a[i][j] = visit[i][j] = path[i][j] = 0;

    scanf("%d %d %d %d", &m, &n, &tx, &ty);
    if(m == 0 || n==0)
        return false;

    for(i=1 ; i<=n ; i++)
    {
        scanf("%s", &tmp[1]);
        for(j=1 ; j<=m ; j++)
        {
            if(tmp[j] == 'E')
                a[i][j] = 0;
            else if(tmp[j] == 'S')
                a[i][j] = 1;
            else if(tmp[j] == 'W')
                a[i][j] = 2;
            else
                a[i][j] = 3;
        }
    }

    while(1)
    {
        sy = ty;
        sx = tx;
        visit[sy][sx] = path[sy][sx]+1;

        ty = sy+dy[a[sy][sx]];
        tx = sx+dx[a[sy][sx]];

        if(visit[ty][tx] != 0)
        {
            printf("cycle %d\n", visit[sy][sx]-visit[ty][tx]+1);
            break;
        }
        path[ty][tx] = visit[sy][sx];
        if(ty>n || ty<=0 || tx>m || tx<=0)
        {
            printf("exit %d\n", visit[sy][sx]);
            break;
        }
    }
    return true;
}

int main()
{
    while(pro())
    {

    }
    return 0;
}
