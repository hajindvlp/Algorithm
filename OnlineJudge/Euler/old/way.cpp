#include <stdio.h>

int dp[501][501], a[501][501], N, M, i, j;
int nx[] = { 1,-1,0,0 }, ny[] = { 0,0,1,-1 };

int solve(int x, int y)
{
   int ret = 0;
   if(x == 0 || y == 0)
      return 0;
   if(x == N && y == M)
      return 1;
   if(dp[x][y] != -1)
      return dp[x][y];
   for(int i = 0; i < 4; i++)
      if(a[x][y] > a[x + nx[i]][y + ny[i]])
         ret += solve(x + nx[i], y + ny[i]);
   return dp[x][y] = ret;
}

int main()
{
   scanf("%d %d", &N, &M);
   for(i = 1; i <= N; i++)
      for(j = 1; j <= M; j++)
         scanf("%d", &a[i][j]),dp[i][j]=-1;

   printf("%d", solve(1,1));
   return 0;
}
