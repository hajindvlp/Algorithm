#include <stdio.h>
#include <queue>
using namespace std;

int n, a[101][101], path[101];
int p[101], cnt, visit[101];
queue<int> Q;

int main()
{
    int i, j, y;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            scanf("%d", &a[i][j]);

    Q.push(1);
    while(!Q.empty())
    {
        y = Q.front(), Q.pop();
        for(i=1 ; i<=n ; i++)
            if(visit[i])
                a[i][y] = 1;
        visit[y] = 1;
        for(i=1 ; i<=n ; i++)
            if(a[y][i] && visit[i] == 0)
                Q.push(i);
    }

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=n ; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
