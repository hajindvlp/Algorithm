#include <stdio.h>
#include <queue>
using namespace std;

int n, a[41], m, cnt;

void rec(int lev, int sum) {
    if(lev>n) {
        if(sum == m) cnt++;
    } else {
        rec(lev+1, sum+a[lev]);
        rec(lev+1, sum);
    }
}

int main()
{
    int i, len, j;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);
    rec(1, 0);
    printf("%d", cnt);
    return 0;
}
