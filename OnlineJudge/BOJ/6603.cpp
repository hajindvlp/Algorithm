#include <stdio.h>

int a[14], visit[14], n;

void rec(int lev, int cnt) {
    if(lev>n || cnt == 6) {
        if(cnt == 6) {
            for(int i=1 ; i<=n ; i++) if(visit[i]) printf("%d ", a[i]);
            printf("\n");
        }
    } else {
        visit[lev] = 1;
        rec(lev+1, cnt+1);
        visit[lev] = 0;
        rec(lev+1, cnt);
    }
}

int pro() {
    int i;

    scanf("%d", &n);
    if(n == 0) return 0;
    for(i=1 ; i<=n ; i++) scanf("%d", &a[i]);

    rec(1, 0);
    return 1;
}

int main() {
    while(pro()) printf("\n");
}