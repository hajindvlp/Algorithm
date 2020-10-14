#include <iostream>
#include <vector>
#include <string>
using namespace std;

int a[16][30], tar[30];
int N, M, ans=1000;
bool visit[16];
string vv, tv;

void out(int cnt, vector<int> sum) {
  bool flag = true;
  for(int i=1 ; i<=N ; i++) if(sum[i] < tar[i]) flag = false;

  if(flag && ans>=cnt) {
    ans = cnt;
    tv.clear();
    for(int i=1 ; i<=N ; i++) 
      if(visit[i]) tv.append(to_string(i)+" ");
    if(vv.empty() || vv > tv) {
      vv = tv;
    }
  }
}

void rec(int lev, int cnt, vector<int> sum) {
  if(lev >= M) {
    out(cnt, sum);
  } else {
    rec(lev+1, cnt, sum);

    for(int i=1 ; i<=N ; i++) sum[i] += a[lev+1][i];
    visit[lev+1] = 1;
    rec(lev+1, cnt+1, sum);
    visit[lev+1] = 0;
    for(int i=1 ; i<=N ; i++) sum[i] -= a[lev+1][i];
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int i, j;

  cin >> N;
  for(i=1 ; i<=N ; i++) cin >> tar[i];
  cin >> M;
  for(i=1 ; i<=M ; i++) for(j=1 ; j<=N ; j++) cin >> a[i][j];

  rec(0, 0, vector<int>(N+1, 0));

  cout << ans << "\n" << vv;
}