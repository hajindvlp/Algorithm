#include <stdio.h>

int d[501][501], a[501][501];
int n, m;
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

int pro(int y, int x) {
    if(y == 1 && x == 1) return 1;
    else if(d[y][x]>0) {
        return d[y][x];
    }
    else {
        int ty, tx, i, t = 0;
        for(i=0 ; i<4 ; i++) {
            ty = y+dy[i];
            tx = x+dx[i];
            if(ty>0 && ty<=n && tx>0 && tx<=m && a[ty][tx]>a[y][x]) {
                t += pro(ty, tx);
            } 
        }
        return d[y][x] = t;
    }
}

int main() {
    int i, j;

    scanf("%d%d",&n,&m);
    for(i=1 ; i<=n ; i++) for(j=1 ; j<=m ; j++) scanf("%d", &a[i][j]), d[i][j] = -1;
    
    d[1][1] = 1;

    printf("%d\n", pro(n, m));
}

