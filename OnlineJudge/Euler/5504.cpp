#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;

int N, M;
int a[305][305], d[305][305];
bool isVal[28];
pair<int, int> tel[305][305];
pair<pair<int, int>, pair<int, int> > tpp[28];
queue<pair<int, int> > Q;
int dy[4]={1, 0, -1, 0}, dx[4]={0, 1, 0, -1};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int i, j;
  int sy, sx, ey, ex;
  int yy, xx, ty, tx, tty, ttx;
  string s;

  cin >> N >> M;
  for(i=1 ; i<=N ; i++) {
    cin >> s;
    for(j=0 ; j<M ; j++) {
      d[i][j+1] = INF;
      if(s[j] == '#') a[i][j+1] = -1;
      else if(s[j] == '@') sy = i, sx = j+1;
      else if(s[j] == '=') ey = i, ex = j+1;
      else if('A'<=s[j] && s[j]<='Z') {
        if(!isVal[s[j]-'A'+1]) {
          tpp[s[j]-'A'+1].first = {i, j+1};
          isVal[s[j]-'A'+1] = true;
        } else {
          tpp[s[j]-'A'+1].second = {i, j+1};
          tel[tpp[s[j]-'A'+1].second.first][tpp[s[j]-'A'+1].second.second] = tpp[s[j]-'A'+1].first;
          tel[tpp[s[j]-'A'+1].first.first][tpp[s[j]-'A'+1].first.second] = tpp[s[j]-'A'+1].second;
        }
      }
    }
  }

  Q.push({sy, sx});
  d[sy][sx] = 0;
  while(!Q.empty()) {
    yy = Q.front().first;
    xx = Q.front().second;
    Q.pop();
    for(i=0 ; i<4 ; i++) {
      ty = yy+dy[i];
      tx = xx+dx[i];
      if(tel[ty][tx].first!=0) {
        tty = tel[ty][tx].first;
        ttx = tel[ty][tx].second;
        ty = tty;
        tx = ttx;
      }
      if(ty>0 && ty<=N && tx>0 && tx<=M && a[ty][tx] == 0 && d[ty][tx] > d[yy][xx] + 1) {
        Q.push({ty, tx});
        d[ty][tx] = d[yy][xx]+1;
      }
    }
  }

  cout << d[ey][ex] << "\n";
}