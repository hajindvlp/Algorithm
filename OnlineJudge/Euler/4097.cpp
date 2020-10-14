#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define N 12
#define M 6

using namespace std;

int a[N][M];
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
int shape, idx, c1, c2;
int cnt;
queue<int> ans;
queue<pair<int, int> > Q, bb;

void fall() {
  int i, j, k;
  bool flag;

  for(i=0 ; i<M ; i++) {
    flag = false;
    for(j=0 ; j<N ; j++) {
      if(flag == false && a[j][i] != 0) flag = true;
      if(flag && a[j][i] == 0) 
        for(k=j ; k>0 ; k--)  {
          a[k][i] = a[k-1][i];
          a[k-1][i] = 0;
        }
    }
  }
}

int bfs() {
  int ccnt, i, j, k;
  int yy, xx, ty, tx;
  bool visit[N][M];

  for(i=0; i<N ; i++) for(j=0 ; j<M ; j++) visit[i][j] = false;
  ccnt = 0;

  for(i=0 ; i<N ; i++) {
    for(j=0 ; j<M ; j++) {
      if(!visit[i][j] && a[i][j] != 0) {
        Q.push({i, j});
        visit[i][j] = true;
        bb.push({i, j});
        while(!Q.empty()) {
          yy = Q.front().first;
          xx = Q.front().second;
          Q.pop();
          for(k=0 ; k<4 ; k++) {
            ty = yy+dy[k];
            tx = xx+dx[k];
            if(ty>=0 && ty<N && tx>=0 && tx<M && !visit[ty][tx] && a[ty][tx] == a[i][j]) {
              visit[ty][tx] = true;
              Q.push({ty, tx});
              bb.push({ty, tx});
            }
          }
        }
        if(bb.size() >= 4) {
          ccnt += bb.size();
          while(!bb.empty()) {
            a[bb.front().first][bb.front().second] = 0;
            bb.pop();
          }
        } else {
          while(!bb.empty()) bb.pop();
        }
      }
    }
  }

  return ccnt;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int i, j, x;

  for(i=0 ; i<N ; i++) 
    for(j=0 ; j<M ; j++)
      cin >> a[i][j];
  cin >> shape >> idx >> c1 >> c2;

  if(shape == 1) {
    a[0][idx-1] = c1;
    a[1][idx-1] = c2;
  } else {
    a[0][idx-1] = c1;
    a[0][idx] = c2;
  }

  while(1) {
    fall();
    x = bfs();
    if(x) {
      cnt++;
      ans.push(x);
    } else {
      break;
    }
  }

  cout << cnt << "\n";
  for(i=0 ; i<cnt ; i++) {
    cout << ans.front() << " ";
    ans.pop();
  }
}