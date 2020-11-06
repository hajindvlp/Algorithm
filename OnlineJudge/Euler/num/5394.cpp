#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <assert.h>

using namespace std;

typedef long long ll;

int N, C, A[100005];
int main() {
  scanf("%d %d", &N, &C);
  int k = 1;
  for (int i = 1; i <= C; i++) {
    int n;
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
      A[k++] = i;
    }
  }
  for (int i = 1; i <= N / 2; i++) {
    printf("%d %d\n", A[i], A[i + N / 2]);
  }
  return 0;
}
