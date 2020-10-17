#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>
#define INF 1000000000
using namespace std;

int N, M, A;
int a[105][105], na[105][105], path[105][105], dist[105][105], nDist[105][105];
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
queue<pair<int, int> > Q;
stack<int> trace;
char tc[] = {'R', 'D', 'L', 'U'};

void bfs(int sy, int sx, int cc) {
  int i, yy, xx, ty, tx;

  Q.push({sy, sx});
  while(!Q.empty()) {
    yy = Q.front().first;
    xx = Q.front().second;
    Q.pop();

    for(i=0 ; i<4 ; i++) {
      ty = yy+dy[i];
      tx = xx+dx[i];
      if(ty>0 && ty<=N && tx>0 && tx<=M && a[ty][tx] != 1 && nDist[ty][tx] > nDist[yy][xx] + 1) {
        nDist[ty][tx] = nDist[yy][xx] + 1;
        path[ty][tx] = i;
        Q.push({ty, tx});
      }
    }
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int i, j, k, cnt=0;
  int sy, sx, ey, ex, ty, tx;
  string s;

  cin >> N >> M >> A;
  for(i=1 ; i<=N ; i++) {
    cin >> s;
    for(j=1 ; j<=M ; j++) {
      dist[i][j] = INF;
      nDist[i][j] = INF;

      if(s[j-1] == 'F') a[i][j] = 1;
      else if(s[j-1] == 'Y') sy = i, sx = j;
      else if(s[j-1] == 'S') ey = i, ex = j;
    }
  }

  dist[sy][sx] = nDist[sy][sx] = 0;
  while(1) {
    for(i=1 ; i<=N ; i++) 
      for(j=1 ; j<=M ; j++)
        if(a[i][j]!=1 && dist[i][j] <= A*cnt) 
          bfs(i, j, dist[i][j]);

    cnt++;
    bool flag = true;
    for(i=1 ; i<=N ; i++) 
      for(j=1 ; j<=M ; j++) {
        if(nDist[i][j] <= A*cnt && dist[i][j] != nDist[i][j]) flag = false;
        if(nDist[i][j] <= A*cnt) dist[i][j] = nDist[i][j];
        if(a[i][j] == 1)
          for(k=0 ; k<4 ; k++) {
            ty = i+dy[k];
            tx = j+dx[k];
            if(ty>0 && ty<=N && tx>0 && tx<=M && a[ty][tx] != 1) na[ty][tx] = 1;
          }
      }
    
    if(dist[ey][ex] != INF) break;

    for(i=1 ; i<=N ; i++) for(j=1 ; j<=M ; j++) a[i][j] = na[i][j] ? 1 :a[i][j];

    for(i=1 ; i<=N ; i++) {
      for(j=1 ; j<=M ; j++) {
        if(a[i][j]) cout << "x ";
        else if(dist[i][j] == INF) cout << ". ";
        else cout << path[i][j] << " ";
      }
      cout << "\n";
    }
      cout << "\n";
    if(flag) {
      cout << 0;
      return 0;
    }
  }
  
  ty = ey, tx = ex;
  cout << nDist[ey][ex] << "\n";
  while(ey != sy && ex != sx) {
    ey = ty, ex = tx;
    trace.push(path[ey][ex]);
    ty = ey - dy[path[ey][ex]];
    tx = ex - dx[path[ey][ex]];
    cout << ty << " " << tx << "\n  ";
  }
  while(!trace.empty()) {
    cout << tc[trace.top()] << "\n";
    trace.pop();
  }   
}