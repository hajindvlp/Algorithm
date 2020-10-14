#include <iostream>
#define N 19
using namespace std;

int a[N+1][N+1];
bool visit[4][N+1][N+1];
int dy[4] = {-1, 0, 1, 1}, dx[4] = {1, 1, 1, 0};

bool check(int sy, int sx, int dd) {
  int ty, tx, i;

  for(i=0; i<5 ; i++) {
    ty = sy + i * dy[dd];
    tx = sx + i * dx[dd];
    if(!(ty>0 && ty<=N && tx>0 && tx<=N)) return false;
    if(a[ty][tx]!=a[sy][sx]) return false; 
    visit[dd][ty][tx] = true;
  }
  ty = sy + i * dy[dd];
  tx = sx + i * dx[dd];
  if(!(ty>0 && ty<=N && tx>0 && tx<=N) || a[ty][tx]!=a[sy][sx]) 
    return true;
  else return false;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int i, j, k;
  int winner = 0, yy, xx;

  for(i=1 ; i<=N ; i++) for(j=1 ; j<=N ; j++) cin >> a[i][j];

  for(i=1 ; i<=N ; i++) 
    for(j=1 ; j<=N ; j++) 
      if(a[i][j]) 
        for(k=0 ; k<4 ; k++) 
          if(!visit[k][i][j]) {
            bool t = check(i, j, k);
            if(t) {
              winner = a[i][j];
              yy = i;
              xx = j;
            }
          }

  if(winner) {
    cout << winner << "\n" << yy << " " << xx;
  } else {
    cout << 0;
  }
}