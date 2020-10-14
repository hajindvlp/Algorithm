#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 1000000000
using namespace std;

queue<pair<int, int> > Q;
int N, a, b;
bool visitA[500005][20], visitB[500005][20];
int pow2[20], d[2]={1, -1};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int i, j, x, y;
  cin >> N >> a >> b;

  memset(visitA, false, sizeof(visitA[0][0]) * (N+1) * 20);
  memset(visitB, false, sizeof(visitB[0][0]) * (N+1) * 20);
  pow2[0] = 1;
  for(i=1 ; i<20 ; i++) pow2[i] = pow2[i-1]*2;

  Q.push({a, 0});
  visitA[a][0] = 1;
  while(!Q.empty()) {
    x = Q.front().first;
    y = Q.front().second;
    Q.pop();
    for(i=0 ; i<2 ; i++) 
      if(x + d[i] * pow2[y] <= N && x + d[i] * pow2[y] > 0 && !visitA[x + d[i]*pow2[y]][y+1]) {
        visitA[x+d[i]*pow2[y]][y+1] = true;
        Q.push({x+d[i]*pow2[y], y+1});
      }
  }
  Q.push({b, 0});
  visitB[b][0] = 1;
  while(!Q.empty()) {
    x = Q.front().first;
    y = Q.front().second;
    Q.pop();
    for(i=0 ; i<2 ; i++) 
      if(x + d[i] * pow2[y] <= N && x + d[i] * pow2[y] > 0 && !visitB[x + d[i]*pow2[y]][y+1]) {
        visitB[x+d[i]*pow2[y]][y+1] = true;
        Q.push({x+d[i]*pow2[y], y+1});
      }
  }

  for(i=1 ; i<20 ; i++) {
    for(j=1 ; j<=N ; j++) 
      if(visitA[j][i] && visitB[j][i]) {
        cout << i << "\n";
        return 0;
      }
  }
  cout << "-1\n";
}