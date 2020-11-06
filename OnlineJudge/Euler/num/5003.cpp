#include <stdio.h>
#define INF 1000000000
#define N 50

int n, m;
int d[2][N+1][N+1];

void f(int lev, int pre, int car, int isv)
{
    int i, j;

    for(i=0 ; i<=pre ; i++)
        for(j=0 ; j<=i ; j++)
            if(i+j<=m && i+j!=0 && pre-i>=car-i && pre>=car && d[isv][pre][car]>lev)
            {
                d[isv][pre-i][car-i] = lev;
                f(lev+1, pre-i, car-i, !isv);
            }
}

int main()
{
    int i, j, num, mx;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            d[0][i][j] = d[1][i][j] = INF;

    d[0][n][n] = 0;
    f(1, n, n, 1);NN
    printf("%d", d[1][n][n]);
 }
