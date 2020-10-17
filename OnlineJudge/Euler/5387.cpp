#include <stdio.h>
#include <queue>

using namespace std;

#define MAX 1000
const int dir[8][2]={{-1,-1},{-1,0},{-1,1},{1,-1},{1,0},{1,1},{0,-1},{0,1}};

int N,M,mat[MAX][MAX],cnt;
bool mark[MAX][MAX];
queue<int> que;

void floodfill(int y,int x)
{
	que.push(y);
	que.push(x);

	bool peak=true;
	do
	{
		y=que.front(); que.pop();
		x=que.front(); que.pop();
		for (int i=0; i<8; i++)
		{
			int newY=y+dir[i][0],newX=x+dir[i][1];
			if (newY>=0 && newX>=0 && newY<N && newX<M)
            {
				if (mat[y][x]<mat[newY][newX]) peak=false;
				else if (mat[y][x]==mat[newY][newX] && !mark[newY][newX])
				{
					mark[newY][newX]=true;
					que.push(newY);
					que.push(newX);
				}
            }
		}
	}
	while (!que.empty());

	if (peak) cnt++;
}

int main()
{
    int i, j;

    scanf("%d %d", &N, &M);
    for(i=0 ; i<N ; i++)
        for(j=0 ; j<M ; j++)
            scanf("%d", &mat[i][j]);

	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			if (mat[i][j]>0 && !mark[i][j]) floodfill(i,j);

    printf("%d", cnt);
    return 0;
}
