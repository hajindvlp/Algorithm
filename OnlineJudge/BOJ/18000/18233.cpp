#include <iostream>
#include <algorithm>
using namespace std;

int N, P, E;
int visit[21], sum[21];
bool flag = false;
pair<int, int> a[21];

void res() {
  int rd = E;
  for(int i=1 ; i<=N ; i++) 
    if(visit[i]) {
      rd -= a[i].first;
      sum[i] = a[i].first;
    } 

  if(rd > 0) {
    for(int i=1 ; i<=N ; i++) {
      if(rd == 0) break;
      if(visit[i]) {
        if(a[i].second - a[i].first <= rd) {
          sum[i] += (a[i].second-a[i].first);
          rd -= (a[i].second-a[i].first);
        } else {
          sum[i] += rd;
          rd = 0;
        }
      }
    }
  } 

  for(int i=1 ; i<=N ; i++) 
    cout << sum[i] << " ";
  flag = true;
}

void rec(int mn, int mx, int idx, int lev) {
  if(flag)
    return;
  if(lev == P) {
    if(mn <= E && E <= mx) res();
  }
  else 
    for(int i=idx+1 ; i<=N-P+lev+1 ; i++) {
      visit[i] = 1;
      rec(mn+a[i].first, mx+a[i].second, i, lev+1);
      visit[i] = 0;
    }
}

int main() {
  int i, x, y;
  cin >> N >> P >> E;
  for(i=1 ; i<=N ; i++) {
    cin >> x >> y;
    a[i] = {x, y};
  }

  rec(0, 0, 0, 0);
  if(!flag)
    cout << "-1 \n";
}