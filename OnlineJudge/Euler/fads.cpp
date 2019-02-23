#include <stdio.h>
#include <algorithm>
using namespace std;

int n, l, k, a[1000001], cnt;

int main()
{
    int i;

    scanf("%d %d %d" , &n, &l, &k);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);
    sort(a+1, a+n+1);

    for(i=1 ; i<=n ; i++)
    {
        if(a[i]<=l)
        {
            cnt++;
            l+=k;
        }
        else
            break;
    }
    printf("%d", cnt);
    return 0;
}
