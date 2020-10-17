#include <iostream>
#include <queue>
using namespace std;

int N, M;
bool a[2][505][505];
queue<int> Q;

int bfs(int ss, int k) {
  int cnt = 0, i, yy;
  bool visit[505];
  for(i=1 ; i<=N ; i++) visit[i] = false;
  cnt = 0;
  Q.push(ss);
  visit[ss] = 1;
  while(!Q.empty()) {
    cnt++;
    yy = Q.front();
    Q.pop();
    for(i=1 ; i<=500 ; i++) {
      if(a[k][yy][i] && !visit[i]) {
        Q.push(i);
        visit[i] = 1;
      }
    }
  }

  return cnt;
}

int main() {
  int i, j;
  int x, y, ans=0;

  cin >> N >> M;
  for(i=1 ; i<=M ; i++) {
    cin >> x >> y;
    a[0][x][y] = 1;
    a[1][y][x] = 1;
  }

  for(i=1 ; i<=N ; i++) {
    int cnt1 = bfs(i, 0);
    int cnt2 = bfs(i, 1);

    if(cnt1 + cnt2-2 == N-1) ans++;
  }
  cout << ans << "\n";
}