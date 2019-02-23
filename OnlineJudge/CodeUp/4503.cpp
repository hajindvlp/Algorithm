#include <stdio.h>
#include <queue>
using namespace std;

int n, m;
int a[101][101], visit[101], cnt;
queue<int> Q;

int main()
{
    int i;
    int x, y;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=m ; i++)
        scanf("%d %d", &x, &y), a[x][y] = a[y][x] = 1;

    Q.push(1);
    while(!Q.empty())
    {
        x = Q.front();
        Q.pop();
        for(i=1 ; i<=n ; i++)
            if(a[x][i] == 1 && visit[i] == 0)
                cnt++, Q.push(i), visit[i] = 1;
    }
    printf("%d", cnt-1);
    return 0;
}
