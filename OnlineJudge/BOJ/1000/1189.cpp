#include <stdio.h>

int a[6][6], visit[6][6];
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
int n, m, k, cnt;

void rec(int y, int x, int dist) {
    if(y == 1 && x == m) {
        if(dist == k) cnt++;
    } else {
        for(int i=0 ; i<4 ; i++) {
            int ty = y+dy[i];
            int tx = x+dx[i];
            if(ty>0 && ty<=n && tx>0 && tx<=m && visit[ty][tx] == 0 && a[ty][tx] != -1) {
                visit[y][x] = 1;
                rec(ty, tx, dist+1);
                visit[y][x] = 0;
            }
        }
    }
}

int main() {
    int i, j;
    char s[10];

    scanf("%d %d %d", &n, &m, &k);
    for(i=1 ; i<=n ; i++) {
        scanf("%s", &s[1]);
        for(j=1 ; j<=m ; j++) 
            if(s[j] == 'T') a[i][j] = -1;
    }

    rec(n, 1, 1);
    printf("%d", cnt);
}