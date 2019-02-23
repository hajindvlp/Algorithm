#include <stdio.h>

int n, m, a[21], cnt;
int tmp;

void rec(int sum, int lev)
{
    int i;
    tmp++;
    if(lev==m)
    {
        if(sum == n)
            cnt++;
    }
    else
    {
        rec(sum+a[lev+1], lev+1);
        rec(sum-a[lev+1], lev+1);
    }
}

int main()
{
    int i;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=m ; i++)
        scanf("%d", &a[i]);

    rec(0, 0);
    printf("%d\n", cnt);
    return 0;
}
