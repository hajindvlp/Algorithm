#include <stdio.h>
#include <queue>
using namespace std;

queue<int> Q;

int n, m, a[301][301];
int d[301][301], cnt = 0, visit[301][301], dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

bool is2()
{
    int i, j;
    int xx, yy, tx, ty;
	int acnt = 0;

    for(i=1 ; i<=n ; i++) {
        for(j=1 ; j<=m ; j++)
            if(a[i][j] != 0) {
                Q.push(i), Q.push(j);
                break;
            }
        if(j != m+1)
            break;
    }

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            visit[i][j] = 0;

    while(!Q.empty())
    {
        yy = Q.front(), Q.pop();
        xx = Q.front(), Q.pop();
        visit[yy][xx] = 1;
        for(i=0 ; i<4 ; i++)
        {
            ty = yy+dy[i];
            tx = xx+dx[i];
            if(ty>0 && ty<=n && tx>0 && tx<=m && a[ty][tx]!=0 && visit[ty][tx] == 0) {
                Q.push(ty), Q.push(tx);
        		visit[ty][tx] = 1;
			}
        }
    }

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            if(visit[i][j] == 0 && a[i][j] != 0)
                return false;

	for(i=1 ; i<=n ; i++)
		for(j=1 ; j<=m ; j++)
			if(a[i][j] != 0)
				acnt++;

	if(acnt == 0) {
		cnt = -1;
		return false;
	}
    return true;
}

int main()
{
    int i, j, k;
    int tmp;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            scanf("%d", &a[i][j]);

    while(is2())
    {
        cnt++;
        for(i=1 ; i<=n ; i++)
            for(j=1 ; j<=m ; j++) {
                d[i][j] = 0;
                if(a[i][j] != 0)
                {
                    tmp = 0;
                    for(k=0 ; k<4 ; k++)
                        if(i+dy[k]>0 && i+dy[k]<=n && j+dx[k]>0 && j+dx[k]<=m && a[i+dy[k]][j+dx[k]] == 0)
                            tmp++;
                    d[i][j] = tmp;
                }
			}
        for(i=1 ; i<=n ; i++)
            for(j=1 ; j<=m ; j++)
            {
                a[i][j] -= d[i][j];
                if(a[i][j]<0)
                    a[i][j] = 0;
            }
    }
	if(cnt == -1) printf("0");
	else printf("%d", cnt);
    return 0;
}
