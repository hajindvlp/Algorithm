#include <stdio.h>
#include <algorithm>
using namespace std;

pair<int, int> a[5];
int e[9];

int cal(int x){ return abs(a[1].first+x)+abs(a[1].second+x)+abs(a[2].first+x)+abs(a[2].first-x)+abs(a[3].first-x)+abs(a[3].first+x)+abs(a[4].first-x)+abs(a[4].first-x); }

int main()
{
    int i, j;
    int mx = 1000000000, ans;

    for(i=1 ; i<=8 ; i++)
    {
        scanf("%d", &e[i]);
        if(i%2 == 0)
            a[i/2] = make_pair(e[i-1], e[i]);
    }
    sort(a+1, a+5);

    for(i=1 ; i<=8 ; i++)
        if(mx>cal(e[i]))
            mx = cal(e[i]), ans = 2*e[i];

    printf("%d", ans);
    return 0;
}
