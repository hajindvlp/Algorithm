#include <stdio.h>
#include <algorithm>
#define INF 2000000000
#define MAX 1001
using namespace std;

int n, a[MAX], d[MAX], cnt, mx, path[MAX], idx[MAX];
int ans[MAX];

int main()
{
    int i, k, j, cnt;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        d[i] = INF;

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        k = lower_bound(d + 1, d + i, a[i]) - d;
        if (k > mx) mx = k;

        d[k] = a[i];
        idx[k] = i;
        path[i] = idx[k-1];
    }

    k = idx[mx];
    cnt = 0;
    while (k) {
        ans[++cnt] = k;
        k = path[k];
    }
    printf("%d\n", mx);
    for (i = mx; i >= 1; i--) printf("%d ", a[ans[i]]);
}
