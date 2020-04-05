#include <stdio.h>
#include <algorithm>
using namespace std;

int visit[9], n, m;
int a[9], o[9];

void rec(int lev, int mx, int cnt) {
    if(lev>n || cnt == m) {
        if(cnt == m) {
            for(int i=1 ; i<=m ; i++) printf("%d ", o[a[i]]);
            printf("\n");
        }
    } else {
        for(int i=1 ; i<=n ; i++)
            if(visit[i] == 0) {
                a[lev] = i;
                rec(lev+1, i, cnt+1);
            }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i=1 ; i<=n ; i++) scanf("%d", &o[i]);
    sort(o+1, o+n+1);
    rec(1, 1, 0);
}