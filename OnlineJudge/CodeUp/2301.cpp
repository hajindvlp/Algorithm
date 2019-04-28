#include <stdio.h>

int n, m, mx = -1, smx = -1;
int visit[11], apath[11], a[11];

void rec(int lev, int sum, int cnt)
{
    int i;

    if(lev>m)
    {
        if((sum<=n && sum>smx) || (sum == smx && cnt>mx))
        {
            mx = cnt;
            smx = sum;
            for(i=1 ; i<=m ; i++)
                apath[i] = visit[i];
        }
    }
    else
    {
        visit[lev] = 1;
        rec(lev+1, sum+a[lev], cnt+1);
        visit[lev] = 0;
        rec(lev+1, sum, cnt);
    }
}


int main()
{
    int i, j;
    bool is = false;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=m ; i++)
        scanf("%d", &a[i]);

    rec(1, 0, 0);

    for(i=1 ; i<=m ; i++)
        if(apath[i])
            printf("%d ", a[i]), is = true;
    if(!is)
        printf("-1");
    return 0;
}
