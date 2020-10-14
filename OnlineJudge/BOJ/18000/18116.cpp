#include <iostream>
using namespace std;

int N;
int p[1000005], cnt[1000005];

int f(int x) {
  if(p[x] == x) return x;
  return p[x] = f(p[x]);
}

void comb(int x, int y) {
  x = f(x);
  y = f(y);
  if(x == y) return;
  if(cnt[x] > cnt[y]) {
    p[y] = x;
    cnt[x] += cnt[y];
  }  else {
    p[x] = y;
    cnt[y] += cnt[x];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int i, x, y;
  char c;

  cin >> N;
  for(i=1 ; i<=1000000 ; i++) p[i] = i, cnt[i] = 1;
  for(i=1 ; i<=N ; i++) {
    cin >> c;
    if(c == 'I') {
      cin >> x >> y;
      if(x > y) comb(y, x);
      else comb(x, y);
    }
    else {
      cin >> x;
      cout << cnt[f(x)] << "\n";
    }
  }
}