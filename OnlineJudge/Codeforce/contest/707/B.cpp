#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 1000000005
using namespace std;

vector<vector<pair<int, int> > > a;
vector<int> s;
int scheck[100006];
int n, m, k, mn = INF;

int main() {
  int i, j;
  int x, y, z, slen, alen;

  scanf("%d %d %d", &n, &m, &k);
  a.resize(n+1);
  for(i=1 ; i<=m ; i++) {
    scanf("%d %d %d", &x, &y, &z);
    a[x].push_back(make_pair(y, z));
    a[y].push_back(make_pair(x, z));
  }
  for(i=1 ; i<=k ; i++) scanf("%d", &x), s.push_back(x), scheck[x] = 1;

  slen = s.size();
  for(i=0 ; i<slen ; i++) {
    x = s[i];
    alen = a[x].size();
    for(j=0 ; j<alen ; j++) {
      y = a[x][j].first;
      if(scheck[y] != 1 && a[x][j].second < mn) 
        mn = a[x][j].second;
    }
  }
  if(mn == INF) printf("-1");
  else printf("%d", mn);
}