#include <iostream>
#include <queue>
#include <vector>
#define INF 1000000000
using namespace std;

int d[300005];
vector<vector<int> > a;
int N, M, s, e;
queue<int> Q;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int i, x ,y;

  cin >> N >> M >> s >> e;
  a.resize(N+1);
  for(i=1 ; i<=N ; i++) d[i] = INF;

  for(i=1 ; i<=M ; i++) {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  Q.push(s);
  d[s] = 0;
  while(!Q.empty()) {
    x = Q.front(); Q.pop();
    if(x-1 >= 1 && d[x-1] > d[x] + 1) {
      d[x-1] = d[x]+1;
      Q.push(x-1);
    } 
    if(x+1 <= N && d[x+1] > d[x] + 1) {
      d[x+1] = d[x]+1;
      Q.push(x+1);
    } 
    int len = a[x].size();
    for(i=0 ; i<len ; i++) 
      if(d[a[x][i]] > d[x] + 1) {
        d[a[x][i]] = d[x] + 1;
        Q.push(a[x][i]);
      }
  }

  cout << d[e];
}