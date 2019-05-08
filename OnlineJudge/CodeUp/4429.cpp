#include <stdio.h>

int a[21][21];
int w[21][21], h[21][21];
int n;

void check()
{
}

void rec(int lev, int y, int x)
{
    int i, j;

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=n-i+1 ; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    
    if(x>n-y+1)
        x = 1, y++;
    if(y == n+1)
        check();
    else
    {
        a[y][x] = 1;
        rec(lev+1, y, x+1);
        a[y][x] = 0;
        rec(lev+1, y, x+1);
    }
}

int main()
{
    int i, j;

    scanf("%d", &n);
    rec(1, 1, 1);
}
