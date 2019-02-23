#include <stdio.h>
#define INF 1000000000

int d[51][51][51], path[51][51][51];
int a[51][6];
int ans[51];
int ad, cd, dg, n, cnt; 

int main()
{
    int i, j, k, l;
    int x, y, z, nx, ny, nz;

    scanf("%d %d %d %d", &ad, &cd, &dg, &n);
    for(i=0 ; i<=ad ; i++)
        for(j=0 ; j<=cd ; j++)
            for(k=0 ; k<=dg ; k++)
                d[i][j][k] = INF;

    d[0][0][0] = 0;

    for(i=1 ; i<=n ; i++)
        scanf("%d %d %d %d", &a[i][1], &a[i][2], &a[i][3], &a[i][4]);

    for(i=1 ; i<=n ; i++)
        for(j=a[i][1] ; j<=ad ; j++)
            for(k=a[i][2] ; k<=cd ; k++)
                for(l=a[i][3] ; l<=dg ; l++)
                    if(d[j][k][l]>d[j-a[i][1]][k-a[i][2]][l-a[i][3]]+a[i][4])
                        d[j][k][l]=d[j-a[i][1]][k-a[i][2]][l-a[i][3]]+a[i][4], path[j][k][l] = i;

    if(d[ad][cd][dg] == INF)
    {
        printf("-1");
        return 0;
    }

    x = ad;
    y = cd;
    z = dg;
    
    while(1)
    {
        if(ans[path[x][y][z]] == 0)
            cnt++;
        ans[path[x][y][z]]++;
        nx = x;
        ny = y;
        nz = z;
        x-=a[path[nx][ny][nz]][1];
        y-=a[path[nx][ny][nz]][2];
        z-=a[path[nx][ny][nz]][3];
        if(x==0 && y==0 && z==0)
            break;
    }

    printf("%d %d\n", d[ad][cd][dg], cnt);
    for(i=1 ; i<=n ; i++)
        if(ans[i]!=0)
            printf("%d %d\n", i, ans[i]);

    return 0;
}