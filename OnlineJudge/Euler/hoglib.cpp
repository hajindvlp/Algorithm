#include <stdio.h>

int n, m;
int a[501][101];

bool process()
{
    int i, j;

    scanf("%d %d", &m, &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            scanf("%d", &a[i][j]);
    for(i=1 ; i<=m ; i++)
    {
        for(j=1 ; j<=n ; j++)
            if(a[j][i] == 0)
                break;
        if(j == n+1)
            return true;
    }
    return false;
}

int main()
{
    int i;
    bool ans[4];
    for(i=1 ; i<=3 ; i++)
        ans[i] = process();

    for(i=1 ; i<=3 ; i++)
    {
        if(ans[i])
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
