#include <stdio.h>

int a[11][11];
int e[4][11][11], p[4][11][11];
int dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};
int emx, pmx, ty, tx, yy, xx;

int main()
{
    int i, j, k, l;
    int esx, esy, psx, psy;
    int ed = 3, pd = 3;
    char c[12];

    for(i=1 ; i<=10 ; i++)
    {
        scanf("%s", &c[1]);
        for(j=1 ; j<=10 ; j++)
        {
            if(c[j] == '*')
                a[i][j] = -1;
            else if(c[j] == 'E')
                esy = i, esx = j;
            else if(c[j] == 'P')
                psy = i, psx = j;
        }
    }

    e[ed][esy][esx] = 1;
    yy = esy, xx = esx;
    while(1)
    {
        ty = yy+dy[ed];
        tx = xx+dx[ed];
        if(a[ty][tx] == -1 || !(ty>0 && ty<=10 && tx>0 && tx<=10))
        {
            ty = xx-dy[ed];
            tx = yy-dx[ed];
            ed = (ed+1)%4;
            ty = yy+dy[ed];
            tx = xx+dx[ed];
            if(e[ed][ty][tx]!=0)
                break;
            e[ed][ty][tx] = e[(ed+3)%4][yy][xx]+2;
        }
        else
        {
            ty = yy+dy[ed];
            tx = xx+dx[ed];
            if(e[ed][ty][tx]!=0)
                break;
            e[ed][ty][tx] = e[ed][yy][xx]+1;
        }
        yy = ty;
        xx = tx;
    }

    p[pd][psy][psx] = 1;
    yy = psy, xx = psx;
    while(1)
    {
        ty = yy+dy[pd];
        tx = xx+dx[pd];
        if(a[ty][tx] == -1 || !(ty>0 && ty<=10 && tx>0 && tx<=10))
        {
            ty = xx-dy[pd];
            tx = yy-dx[pd];
            pd = (pd+1)%4;
            ty = yy+dy[pd];
            tx = xx+dx[pd];
            if(p[pd][ty][tx]!=0)
                break;
            p[pd][ty][tx] = p[(pd+3)%4][yy][xx]+2;
        }
        else
        {
            ty = yy+dy[pd];
            tx = xx+dx[pd];
            if(p[pd][ty][tx]!=0)
                break;
            p[pd][ty][tx] = p[pd][yy][xx]+1;
        }
        yy = ty;
        xx = tx;
    }

    for(i=1 ; i<=10 ; i++)
        for(j=1 ; j<=10 ; j++)  
            for(k=0 ; k<=3 ; k++)   
                for(l=0 ; l<=3 ; l++)
                    if(e[k][i][j]!=0 && p[l][i][j]!=0)
                        
    return 0;
}