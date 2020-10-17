#include <stdio.h>
#include <algorithm>

using namespace std;

int numcnt[101];
int n, m, a[101];
int cnt, ans[101][3];

int main()
{
    int i;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d", &a[i]);
        numcnt[a[i]]++;
    }

    sort(a+1, a+n+1);

    for(i=1 ; i<=n ; i++)
    {
        if(m-a[i]>0 && numcnt[m-a[i]]!=0 && a[i]<=m-a[i])
        {
            cnt++;
            ans[cnt][1] = a[i];
            ans[cnt][2] = m-a[i];
            numcnt[a[i]]--;
            numcnt[m-a[i]]--;
        }
    }

    printf("%d\n", cnt);
    for(i=1 ; i<=cnt ; i++)
        printf("%d %d\n", ans[i][1], ans[i][2]);

    return 0;
}
