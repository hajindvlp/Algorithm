// 간단한 다이나믹 인듯

#include <stdio.h>

int canGo[105], d[105][3 ];
int n, m;

int main() {
    int i, j;
    int x;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++) {
        scanf("%d", &x);
        canGo[x] = -1;
    }


}