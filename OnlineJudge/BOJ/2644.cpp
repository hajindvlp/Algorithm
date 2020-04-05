#include <stdio.h>
#include <queue>
#include <alorithm>
#define INF 1000000000
using namespace std;

int a[101][101], d[101][101];
int n, m, s, e;

int main() {
    int i, j;
    int x, y;

    scanf("%d %d %d %d", &n, &s, &e, &m);
    for(i=1 ; i<=m ; i++) scanf("%d %d", &x, &y), a[x][y] = a[y][x] = 1;
    for(i=1 ; i<=n ; i++) for(j=1 ; j<=n ; j++) d[i][j] = INF;

    
}