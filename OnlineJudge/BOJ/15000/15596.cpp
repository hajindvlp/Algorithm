#include <stdio.h>

long long sum(int *a, int n) {
  long long s = 0;
  for(int i=0 ; i<n ; i++) s += a[i];
  return s;
}