#include <stdio.h>
#include <math.h>
#define INF 1000000

int n;
double a[101][101], mn, dist[101], sum;
double dot[101][3];
int visit[101], v;

int main()
{
    int i, j;

    scanf("%d" ,&n);
    for(i=1 ; i<=n ; i++)
        scanf("%lf %lf", &dot[i][1], &dot[i][2]);

    for(i=1 ; i<=n-1 ; i++)
        for(j=i+1 ; j<=n ; j++)
            a[i][j] = a[j][i] = sqrt(pow(dot[i][1]-dot[j][1], 2.0)+pow(dot[i][2]-dot[j][2], 2.0));

    for(i=1 ; i<=n ; i++)
        dist[i] = INF;
    dist[1] = 0;

    for(i=1 ;  i<=n ; i++)
    {
        mn = INF;
        for(j=1 ; j<=n ; j++)
            if(!visit[j]&& mn>dist[j])
            {
                mn = dist[j];
                v = j;
            }
        visit[v] = 1;
        sum+=mn;
        for(j=1 ; j<=n ; j++)
            if(a[v][j] != 0 && dist[j]>a[v][j])
                dist[j] = a[v][j];
    }
    printf("%.2f", sum);
}
