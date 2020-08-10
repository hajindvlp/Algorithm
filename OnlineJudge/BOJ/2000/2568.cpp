#include <stdio.h>
#include <algorithm>
#define INF 2000000000
#define MAX 1000005
using namespace std;

pair<int, int> p[MAX];
int lookup[MAX], visit[MAX];
int n, a[MAX], d[MAX], cnt, mx, path[MAX], idx[MAX];
int ans[MAX];

int main()
{
    int i, k, j, cnt;
    int x, y;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        d[i] = INF;

    for (i = 1; i <= n; i++) 
        scanf("%d %d", &p[i].first, &p[i].second);
    sort(p + 1, p + n + 1);
    for (i = 1; i <= n; i++) a[i] = p[i].second, lookup[i] = p[i].first;

    for (i = 1; i <= n; i++)
    {
        if (a[i] == 0) continue;
        k = lower_bound(d + 1, d + i, a[i]) - d;
        if (k > mx) mx = k;

        d[k] = a[i];
        idx[k] = i;
        path[i] = idx[k - 1];
    }

    k = idx[mx];
    cnt = 0;
    while (k) {
        ans[++cnt] = k;
        k = path[k];
    }
    printf("%d\n", n-mx);
    for (i = mx; i >= 1; i--) visit[lookup[ans[i]]] = 1;
    for (i = 1; i <= n; i++) if (visit[p[i].first] == 0) printf("%d\n", p[i].first);
}
