#include <stdio.h>
#include <queue>
using namespace std;

queue<int> Q;
int n, m;
int color[201];
bool a[201][201], visit[201];

bool coloring()
{
    int i, j;
    int x, y, xx;

    for(i=1 ; i<=200 ; i++)
    {
        for(j=1 ; j<=200 ; j++)
            a[i][j] = 0;
        visit[i] = 0;
        color[i] = -1;
    }

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=m ; i++)
        scanf("%d %d", &x, &y), a[x][y] = a[y][x] = 1;

    Q.push(1);
    color[1] = 0;
    while(!Q.empty())
    {
        xx = Q.front();
        Q.pop();
        for(i=1 ; i<=n ; i++)
            if(a[i][xx])
            {
                if(color[i] < 0)
                {
                    color[i] = !color[xx];
                    Q.push(i);
                }
                else if(color[i] == color[xx])
                    return false;
            }

    }
    return true;
}

int main()
{
    if(coloring())
        printf("BICOLORABLE\n");
    else
        printf("NOT BICOLORABLE\n");
    if(coloring())
        printf("BICOLORABLE\n");
    else
        printf("NOT BICOLORABLE\n");
    return 0;
}
