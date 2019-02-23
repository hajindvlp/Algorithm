#include <stdio.h>

int n, m, t;
int time[100], a[100][100], indg[100][100];
int visit[100], c[100][100];

int main()
{
    int i, j, k, v;
    char tmp, x ,y;

    scanf("%d %d %d", &n, &m, &t);

    for(i=1 ; i<=n ; i++)
        scanf(" %c %d", &tmp, &time[i]);

    for(i=1 ; i<=m ; i++)
    {
        scanf(" %c %c", &x, &y);
        x = x-'A'+1;
        y = y-'A'+1;
        a[x][y] = 1;
        for(j=1 ; j<=t ; j++)
            indg[j][y]++;
    }

    for(i=1 ; i<=t ; i++)
    {
        for(j=1 ; j<=n ; j++)
        {
            for(k=1 ; k<=n ; k++)
                if(indg[i][k] == 0 && visit[k] == 0)
                {
                    v = k;
                    break;
                }

            visit[v] = 1;
            if(c[i][v]<c[i-1][v])
                c[i][v] = c[i-1][v];
            c[i][v] += time[v];

            for(k=1 ; k<=n ; k++)
                if(visit[k]==0 && indg[i][k]>0 && a[v][k] == 1)
                {
                    indg[i][k]--;
                    if(c[i][v]>c[i][k])
                        c[i][k] = c[i][v];
                }
        }
        for(j=1 ; j<=n ; j++)
            visit[j] = 0;
    }

    printf("%d", c[t][n]);
    return 0;
}
