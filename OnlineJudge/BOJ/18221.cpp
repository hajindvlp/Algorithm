#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int n, d[1001][1001];
pair<int, int> s, p, t;

bool far(pair<int, int> p1, pair<int, int> p2) {
  int len = (pow(p2.second-p1.second, 2) + pow(p2.first-p1.first, 2));
  if(len >= 25) return true;
  return false;
}

bool is3() {
  if(d[s.first][s.second]-d[s.first][p.second-1]-d[p.first-1][s.second]+d[p.first-1][p.second-1] >= 3) return true;
  return false;
}

int main() {
  int i, j, x;

  scanf("%d", &n);
  for(i=1 ; i<=n ; i++) for(j=1 ; j<=n ; j++) {
    scanf("%d", &x);
    d[i][j] = d[i-1][j]+d[i][j-1]-d[i-1][j-1];
    if(x == 1) {
      d[i][j]++;
    } else if(x == 5) {
      p = make_pair(i, j);
    } else if(x == 2) {
      s = make_pair(i, j);
    }
  }

  if(p.first > s.first) {
    t.first = p.first;
    p.first = s.first;
    s.first = t.first;
  } if(p.second > p.second) {
    t.second = p.second;
    p.second = s.second;
    s.second = t.second;
  }

  if(far(p, s) && is3()) printf("1");
  else printf("0");
}