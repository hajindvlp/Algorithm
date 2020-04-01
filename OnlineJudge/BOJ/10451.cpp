// 간단한 BFS인듯
// 맞음

#include <stdio.h>
#include <queue>
using namespace std;

void pro() {
  int n, cnt = 0;
  int a[1005], visit[1005];
  int i, j, x, xx;
  queue<int> Q;

  scanf("%d", &n);
  for(i=1 ; i<=n ; i++) scanf("%d", &a[i]), visit[i] = 0;
  
  for(i=1 ; i<=n ; i++) {
    if(visit[i] == 0) {
      cnt++;
      Q.push(i);
      while(!Q.empty()) {
        xx = Q.front(), Q.pop();
        if(visit[xx] == 0){
          visit[xx] = 1;
          Q.push(a[xx]);
        }
      }
    }
    while(!Q.empty()) Q.pop();
  }

  printf("%d\n", cnt);
} 

int main() {
  int T;

  scanf("%d", &T);
  while(T--) pro();
}