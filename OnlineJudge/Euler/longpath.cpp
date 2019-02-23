#include <stdio.h>

int n, a[101][101], s;
int mx, l;

void isOk(int len, int last)
{
    if(len == mx && l>last)
        l = last;
    else if(len>mx)
        mx = len, l = last;
}

void dfs(int x, int len)
{
    int i;

    for(i=1 ; i<=n ; i++)
        if(a[x][i] != 0)
            dfs(i, len+1);

    if(i == n+1)
        isOk(len, x);
}

int main()
{
    int i;
    int x, y;

    scanf("%d %d", &n, &s);
    do
    {
        scanf("%d %d", &x, &y);
        a[x][y] = 1;
    }while(x != 0 && y != 0);

    for(i=1 ; i<=n ; i++)
        if(a[s][i] != 0)
            dfs(i, 1);
    printf("%d %d", mx, l);
}
