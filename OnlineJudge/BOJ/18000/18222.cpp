#include <stdio.h>
#include <math.h>

long long n;

int rec(long long k, int lev) {
  long long a = 1;

  if(k == 1) return (lev%2)?1:0;
  else {
    for(a=1 ; ; a*=2) 
      if(k > a && k <= a*2) {
        return rec(k-a, lev+1);
      }
  }
}

int main() {
  scanf("%lld", &n);
  printf("%d", rec(n, 0));
}