#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > a;
vector<int> ans;
int N, M, k, cnt;
bool v[2005], uv[2005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  int x, y;
  int i, j;

  cin >> N >> M;
  a.resize(N+1);
  for(i=1 ; i<=M ; i++) {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  cin >> k;
  for(i=1 ; i<=k ; i++) {
    cin >> x;
    v[x] = true;
    uv[x] = true;
  }

  for(i=1 ; i<=N ; i++) {
    if(uv[i]) {
      int len = a[i].size();
      for(j=0 ; j<len ; j++) 
        if(uv[a[i][j]] == false) 
          break;
      if(j == len) {
        ans.push_back(i);
        v[i] = false;
        for(j=0 ; j<len ; j++) 
          if(v[a[i][j]]) 
            v[a[i][j]] = false;
      }
    }
  }

  for(i=1 ; i<=N ; i++) {
    if(v[i]) {
      cout << "-1";
      return 0;
    }
  }
  int len = ans.size();
  cout << len << "\n";
  for(i=0 ; i<len ; i++) cout << ans[i] << " ";

}
