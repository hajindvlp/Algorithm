#include <stdio.h>
#include <queue>
using namespace std;

int n, m, a[101][101], cnt, visit[101];
int xx, x, y;
queue<int> Q;

int main()
{
    int i, j;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=m ; i++)
    {
        scanf("%d %d", &x, &y);
        a[x][y] = a[y][x] = 1;
    }

    visit[1] = 1;
    Q.push(1);
    while(!Q.empty())
    {
        xx = Q.front();
        Q.pop();
        for(i=1 ; i<=n ; i++)
            if(visit[i]!=1 && a[xx][i] == 1)
                visit[i] = 1, Q.push(i), cnt++;
    }

    printf("%d", cnt);
    return 0;
}
