#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n, a[2001], mx;
map<int, int> s[2001];

int main() {
  int i, j;
  int d;

  scanf("%d", &n);
  for(i=1 ; i<=n ; i++) scanf("%d", &a[i]);
  sort(a+1, a+n+1);

  for(i=2 ; i<=n ; i++) {
    for(j=1 ; j<i ; j++) { 
      d = a[i]-a[j];
      if(s[i].count(d) && s[j].count(d) && s[i].at(d) < s[j].at(d)+1)
        s[i][d] = s[j].at(d)+1;
      else if(!s[i].count(d) && s[j].count(d))
        s[i][d] = s[j].at(d)+1;
      else
        s[i][d] = 1;
      mx = (mx<s[i][d])?s[i][d]:mx;
    } 
  }
  printf("%d", mx+1);
}