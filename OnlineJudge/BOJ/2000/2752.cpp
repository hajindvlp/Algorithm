#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
  int a[4], i;

  scanf("%d %d %d", &a[1], &a[2], &a[3]);
  sort(a+1, a+4);
  for(i=1 ; i<=3 ; i++) printf("%d ", a[i]);
}