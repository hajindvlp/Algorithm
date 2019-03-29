#include <stdio.h>
#include <queue>
#include <algorithm>
#define INF 1000000000
using namespace std;

queue<int> Q;

int n, scnt, ecnt;
int a[51][51], d[3][51][51];
int sx, sy, sr, ex, ey, er;

int main()
{
    int i, j;
    char tmp[53];

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%s", &tmp[1]);
        for(j=1 ; j<=n ; j++)
        {
            if(tmp[j] == '1')
                a[i][j] = 1;
            if(tmp[j] == 'B')
                scnt++;
            else if(tmp[j] == 'E')
                ecnt++;
            if(scnt == 1 && tmp[j]!='B')
                sr = 1;
            else
                sr = 2;
            if(ecnt == 1 && tmp[j]!='E')
                er = 1;
            else
                er = 2;
            if(scnt == 2 && sy == 0 && sx == 0)
                sy = i, sx = j;
            if(ecnt == 2 && ey == 0 && ex == 0)
                ey = i, ex = j;
        }
    }

    Q.push(sy), Q.push(sx);
    while(!Q.empty())
    {
        yy = Q.front(), Q.pop();
        xx = Q.front(), Q.pop();

                
    }

    return 0;
}
