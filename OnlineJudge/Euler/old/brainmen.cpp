#include <stdio.h>
#include <algorithm>
#define INF 1000000000
using namespace std;

int a[1001], p[1001];
int n, cnt;

bool isSorted()
{
    int i;

    for(i=1 ; i<=n ; i++)
        if(a[i]!=p[i])
            return false;
    return true;
}

int main()
{
    int i, j, mn, k;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]), p[i] = a[i];

    sort(p+1, p+n+1);
    i = 0;
    while(!isSorted())
    {
        i++;
        mn = INF;
        for(j=i ; j<=n ; j++)
            if(mn>a[j])
                mn = a[j], k = j;

        for(j=k ; j>=i+1 ; j--)
            a[j] = a[j-1];
        a[i] = mn;
        cnt+=k-i;
    }
    printf("%d", cnt);
    return 0;
}
