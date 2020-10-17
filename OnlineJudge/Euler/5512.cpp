#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#define INF 1000000000
using namespace std;


typedef pair<int, pair<int, int> > pii;
int N, C, d[505][505];
bool a[505][505];
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
priority_queue<pii, vector<pii>, greater<pii> > Q;

int main() {
  string s;
  int i, j;
  int sy, sx, ey, ex;
  int cc, yy, xx, tc, ty, tx;

  cin >> N >> C;
  for(i=1 ; i<=N ; i++) {
    cin >> s;
    for(j=1 ; j<=N ; j++) {
      d[i][j] = INF;
      if(s[j-1] == '*') a[i][j] = true;
      else if(s[j-1] == 'S') sy = i, sx = j;
      else if(s[j-1] == 'T') ey = i, ex = j; 
    }
  }

  Q.push({0, {sy, sx}});
  d[sy][sx] = 0;
  while(!Q.empty()) {
    cc = Q.top().first;
    yy = Q.top().second.first;
    xx = Q.top().second.second;
    Q.pop();

    for(i=0 ; i<4 ; i++) {
      ty = yy+dy[i];
      tx = xx+dx[i];
      if(ty>0 && ty<=N && tx>0 && tx<=N) {
        if(a[ty][tx]) tc = cc+C+1;
        else tc = cc+1;
        if(d[ty][tx] > tc) {
          d[ty][tx] = tc;
          Q.push({tc, {ty, tx}});
        }
      }
    }
  }

  cout << d[ey][ex] << "\n";
}