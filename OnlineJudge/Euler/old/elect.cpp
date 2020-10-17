#include <stdio.h>
#include <algorithm>
using namespace std;

pair<pair<int, int>, int> a[50001], b[50001];
int n, m;

void swp(int i)
{
    int tmp;

    tmp = a[i].first.first;
    a[i].first.first = a[i].first.second;
    a[i].first.second = tmp;
}

int main()
{
    int i;
    int x, y;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        scanf("%d %d", &x, &y), a[i] = make_pair(make_pair(x, y), i);

    sort(a+1, a+n+1);

    for(i=n-m+1 ; i<=n ; i++)
        swp(i), b[i-n+m] = a[i];

    sort(b+1, b+m+1);

    printf("%d", b[m].second);
    return 0;
}
