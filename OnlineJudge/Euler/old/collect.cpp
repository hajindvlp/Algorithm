#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m, x[100005], y[100005], px, py;
int cnt1, cnt2;

int main()
{
    int i;

    scanf("%d %d", &n, &m);

    for(i=1 ; i<=m ; i++)
        scanf("%d %d", &x[i], &y[i]);

    sort(x+1,x+1+m);
    sort(y+1,y+1+m);

    px=x[m/2+m%2];
    py=y[m/2+m%2];

    for(i=1 ; i<=m ; i++)
    {
        cnt1+=abs(x[i]-px);
        cnt2+=abs(y[i]-py);
    }

    printf("%d",cnt1+cnt2);
    return 0;
}
