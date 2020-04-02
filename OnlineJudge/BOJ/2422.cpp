#include <stdio.h>

int n, m, cnt;
int a[205][205];

int main() {
    int i, j, k;
    int x, y;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=m ; i++) scanf("%d %d", &x, &y), a[x][y] = a[y][x] = 1;

    for(i=1 ; i<=n ; i++)
        for(j=i+1 ; j<=n ; j++)
            for(k=j+1 ; k<=n ; k++)
                if(!a[i][j] && !a[j][k] && !a[k][i])
                    cnt++;

    printf("%d", cnt);
}