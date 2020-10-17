#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> visit;
vector<int> Euler, H, first, seg;
vector<vector<int> > a;
int N;

void dfs(int xx, int lev) {
  int i, len = a[xx].size();
  visit[xx] = true;
  H[xx] = lev;
  first[xx] = Euler.size();
  Euler.push_back(xx);
  for(i=0 ; i<len ; i++) 
    if(!visit[a[xx][i]]) {
      dfs(a[xx][i], lev+1);
      Euler.push_back(xx);
    }
}

// void init(int node, int l, int h) {

// }

void build() {
  int len = Euler.size(), i;
  for(i=0 ; i<len ; i++) cout << Euler[i] << " ";
  cout << "\n";
  for(i=1 ; i<=N ; i++) cout << first[i] << " ";
  cout << "\n";
  for(i=1 ; i<=N ; i++) cout << H[i] << " ";
  cout << "\n";
  dfs(1, 0);
}

// int lca(int v1, int v2) {
//   return 0;
// }

int main() {
  // cin.tie(NULL);
  // ios_base::sync_with_stdio(false);
  int i, j, x;

  cin >> N;
  a.resize(N+1);
  visit.resize(N+1, false);
  H.resize(N+1, 0);
  for(i=2 ; i<=N ; i++) {
    cin >> x;
    a[x].push_back(i);
  }
  build();
}