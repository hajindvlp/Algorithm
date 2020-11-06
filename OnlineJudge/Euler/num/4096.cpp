#include <stdio.h>
#include <algorithm>
using namespace std;

pair<double, int> a[1001];
int n;

int main()
{
    int i;
    int x, y;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d %d", &x, &y), a[i] = make_pair((double)x/y, i);

    sort(a+1, a+n+1);
    for(i=1 ; i<=n ; i++)
        printf("%d ", a[i].second);

    return 0;
}
