#include <stdio.h>

int d[51][51];
int n, m;
int dy[8]={1, 1, 0, -1, -1, -1, 0, 1}, dx[8]={0, 1, 1, 1, 0, -1, -1, -1};

int main()
{
    int i, j, mn = 0, k, ty, tx;
    int a[51][51];
    char tmp[56];

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%s", &tmp[1]);
        for(j=1 ; j<=m ; j++)
            if(tmp[j] == 'o')
            {
                a[i][j] = 1;
                for(k=0 ; k<8 ; k++)
                {
                    ty = i+dy[k];
                    tx = j+dx[k];
                    if(ty>0 && ty<=n && tx>0 && tx<=m)
                        d[ty][tx]++;
                }
            }
    }

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            if(d[i][j]>mn && !a[i][j])
                mn = d[i][j];

    printf("%d", mn);
}
