#include <stdio.h>

int n;
int a[20][20];

bool check()
{
    int i, j, xcnt = 0, ycnt = 0;

    for(i=1 ; i<=19 ; i++)
        for(j=1 ; j<=19 ; j++)
        {
            if(a[i][j-1] == a[i][j])
            {
                xcnt++;
                if(xcnt==5)
                    return true;
            }
            else
                xcnt = 0;
            if(a[i-1][j] == a[i][j])
            {
                ycnt++;
                if(ycnt==5)
                    return true;
            }
            else
                ycnt = 0;
        }
}

int main()
{
    int i;
    int x, y;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d", &x, &y);
        if(i%2 == 1)
            a[x][y] = 1;
        else
            a[x][y] = -1;

        if(tmp == 0 && check())
            tmp = i;
    }
}
