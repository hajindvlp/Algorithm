#include <stdio.h>
#include <algorithm>
using namespace std;

pair<pair<int, int>, pair<int, int> > a[1001];
int n, m;

int main()
{
    int i, x, y, z, k;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d %d %d", &x, &y, &z, &k);
        a[i] = {{y, z}, {k, x}};
    }
    sort(a+1, a+n+1);    
}
