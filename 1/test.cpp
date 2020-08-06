/*
1. 각 사람의 수 N (<=100,000)와 그 사람이 취업 박람회에 들어온 시간과 나온 시간 (각각 <=1,000,000,000)이 주어질 때, 
가장 사람이 많았던 시간대를 구하시오.
*/

#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int in[100005], out[100005];
int ansIn, ansOut, mx = 0;
pair<int, int> a[100005];

int main() {
  int i;
  int x, y;

  scanf("%d", &n);
  for(i=1 ; i<=n ; i++) scanf("%d %d", &x, &y), a[i] = make_pair(x, y);
  sort(a+1, a+n+1);
  for(i=1 ; i<=n ; i++) in[i] = a[i].first, out[i] = a[i].second;

  for(i=1 ; i<=n ; i++) {
    x = out[i];
    y = lower_bound(in+1, in+n+1, x) - in - 1;
    if(mx < y - i + 1) {
      mx = y - i + 1;
      ansIn = in[y];
      ansOut = x;
    }
  }

  printf("%d %d %d\n", ansIn, ansOut, mx);
}