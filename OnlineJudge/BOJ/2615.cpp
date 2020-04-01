#include <stdio.h>

int a[20][20], visit[4][20][20];
int dy[4]={0, 1, 1, -1}, dx[4]={1, 1, 0, 1};

int main() {
  int i, j, k;
  int yy, xx;
  int cnt;

  for(i=1 ; i<=19 ; i++) for(j=1 ; j<=19 ; j++) scanf("%d", &a[i][j]);

  for(k=0 ; k<3 ; k++) 
    for(i=1 ; i<=19 ; i++) 
      for(j=1 ; j<=19 ; j++) 
        if(a[i][j]>0 && visit[k][i][j] == 0) {
          yy = i, xx = j;
          cnt = 0;
          while(1) {
            if(a[yy][xx] != a[i][j] || yy>19 || xx>19 || yy <= 0 || visit[k][yy][xx] == 1) break;
            cnt++;
            visit[k][yy][xx] = 1;
            yy += dy[k], xx += dx[k];
          }
          if(cnt == 5) {
            printf("%d\n%d %d", a[i][j], i, j);
            return 0;
          }
        }

    for(i=19 ; i>=1 ; i--)
      for(j=1 ; j<=19 ; j++)
        if(a[i][j] > 0 && visit[k][i][j] == 0) {
          yy = i, xx = j;
          cnt = 0;
          while(1) {
            if(a[yy][xx] != a[i][j] || yy>19 || xx>19 || yy <= 0 || visit[k][yy][xx] == 1) break;
            cnt++;
            visit[k][yy][xx] = 1;
            yy += dy[k], xx += dx[k];
          }
          if(cnt == 5) {
            printf("%d\n%d %d", a[i][j], i, j);
            return 0;
          }
        }

  printf("0");
  return 0;
}