#include <stdio.h>
#define INF 100000000

int n, sum;
int a[1001][1001];
int d[1001], visit[1001];
int v, mn;

int main()
{
    int i, j;

    scanf("%d %d", &n, &m);

    for(i=1 ; i<=n ; i++)
        d[i] = INF;
    d[1] = 0;

    for(i=1 ; i<=n ; i++)
    {
        mn = INF;
        for(j=1 ; j<=n ; j++)
            if(!visit[j] && mn>d[j])
            {
                mn = d[j];
                v = j;
            }
        visit[v] = 1;
        sum += mn;
        for(j=1 ; j<=n ; j++)
            if(a[v][j]!=0 && d[j]>a[v][j])
                d[j] = a[v][j];
    }
    printf("%d", sum);
}
