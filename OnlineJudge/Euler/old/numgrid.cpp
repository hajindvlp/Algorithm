#include <stdio.h>

int cnt, a[6][6], dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, s[16000][7];
int tmp[7];

void isOk()
{
    int i, j;

    for(i=1 ; i<=cnt ; i++)
    {
        for(j=1 ; j<=6 ; j++)
            if(s[i][j] != tmp[j])
                break;
        if(j == 7)
            break;
    }
    if(i==cnt+1 || cnt == 0)
    {
        cnt++;
        for(j=1 ; j<=6 ; j++)
            s[cnt][j] = tmp[j];
    }
}

void dfs(int y, int x, int lev)
{
    int i, ty, tx;

    if(lev == 7)
        isOk();
    else
        for(i=0 ; i<4 ; i++)
        {
            ty = y+dy[i];
            tx = x+dx[i];
            if(ty>0 && ty<6 && tx>0 && tx<6)
            {
                tmp[lev] = a[ty][tx];
                dfs(ty, tx, lev+1);
            }
        }
}

int main()
{
    int i, j;

    for(i=1 ; i<=5  ; i++)
        for(j=1 ; j<=5 ; j++)
            scanf("%d", &a[i][j]);
    for(i=1 ; i<=5 ; i++)
        for(j=1 ; j<=5 ; j++)
            dfs(i, j, 1);
    printf("%d", cnt);
    return 0;
}
