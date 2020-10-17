#include <stdio.h>

int n, m, a[17], mx;

void rec(int lev, int sum)
{
    if(lev==n+1)
    {
        if(sum<=m && mx<sum)
            mx = sum;
        return;
    }
    else
    {
        rec(lev+1, sum+a[lev]);
        rec(lev+1, sum);
    }
}

int main()
{
    int i;

    scanf("%d %d", &m, &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);
    rec(1, 0);
    printf("%d", mx);
    return 0;
}
