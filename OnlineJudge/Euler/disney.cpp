#include <stdio.h>
#include <algorithm>
using namespace std;

pair<int, int> a[1001];
int n, cnt;

int main()
{
    int i;
    int x, y;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d", &x, &y);
        a[i] = make_pair(x, y);
    }
    sort(a+1, a+n+1);
    for(i=2 ; i<=n ; i++)
        if(a[i-1].second+1<a[i].first)
        {
            printf("%d %d", a[i-1].second+1, a[i].first-1);
            return 0;
        }
    printf("0");
}
