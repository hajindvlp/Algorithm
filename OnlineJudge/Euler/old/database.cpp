#include <stdio.h>

int n, m, qc;
int a[1001][1001], q[51][1001], ans[1001];

int main()
{
    int i, j, k;
    int acnt, tcnt;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            scanf("%d", &a[i][j]);

    scanf("%d", &qc);
    for(i=1 ; i<=qc ; i++)
        for(j=1 ; j<=m ; j++)
            scanf("%d", &q[i][j]);

    for(i=1 ; i<=qc ; i++)
        for(j=1 ; j<=n ; j++)
        {
            tcnt = acnt = 0;
            for(k=1 ; k<=m ; k++)
            {
                if(q[i][k] != -1)
                    tcnt++;
                if(q[i][k] == -1)
                    continue;
                else if(q[i][k] == a[j][k])
                    acnt++;
            }
            if(tcnt == acnt)
                ans[i]++;
        }

    for(i=1 ; i<=qc ; i++)
        printf("%d\n", ans[i]);

    return 0;
}
