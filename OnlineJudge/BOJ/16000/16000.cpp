#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

queue<pair<int, int>> Q;
int n, m, cnt, snum;
int a[2005][2005], visit[2005][2005];
int dy[4]={0, 1, 0, -1}, dx[4]={1, 0, -1, 0};

int bfs(int sy, int sx) {
  int i, cnt, canGo;
  pair<int, int> pp, tt;
  cnt = 0;
  Q.push({sy, sx});
  visit[sy][sx] = ++snum;
  while(!Q.empty()) {
    pp = Q.front();
    Q.pop();
    for(i=0;i<4;i++) {
      tt = {pp.first+dy[i], pp.second+dx[i]};
      if(tt.first<0 || tt.second<0 || tt.first>=n || tt.second>=m) continue;
      if(tt.first == n-1 || tt.first == 0 || tt.second == )
      if(a[tt.first][tt.second] == 1) {
        if(visit[tt.first][tt.second] != snum) cnt++;
      } 
    }
  }
}

int main() {
  int i, j;
  string t;

  cin >> n >> m;
  for(i=0;i<n;i++) {
    cin >> t;
    for(j=0;j<m;j++) a[i][j]=(t[j]=='#')?1:0;
  }

  for(i=0;i<n;i++) 
    for(j=0;j<n;j++) 
      if(!visit[i][j]) cnt+=bfs(i, j);
}