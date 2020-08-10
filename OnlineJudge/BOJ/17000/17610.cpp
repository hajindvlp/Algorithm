#include <stdio.h>

int n, a[20];
int visit[26000005];

void rec(int lev, int sum) {
    if(lev>n) {
        if(sum>0) visit[sum] = 1;
    } else {
        rec(lev+1, sum+a[lev]);
        rec(lev+1, sum-a[lev]);
        rec(lev+1, sum);
    }
}

int main() {
    int i;
    int ans, cnt, sum;

    scanf("%d", &n);
    cnt = sum = 0;
    for(i=1 ; i<=n ; i++) scanf("%d", &a[i]), sum+=a[i];
    rec(1, 0);

    for(i=1 ; i<=sum ; i++) if(visit[i] == 0) cnt++;
    printf("%d", cnt);
}