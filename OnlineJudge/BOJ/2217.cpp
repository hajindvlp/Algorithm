#include <stdio.h>
#include <algorithm>
using namespace std;

int n, mx;
int a[100001];

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);
    sort(a+1, a+n+1);

    for(i=1 ; i<=n ; i++)
        if(a[i]*(n-i+1)>mx)
            mx = a[i]*(n-i+1);

    printf("%d", mx);

    return 0;
}
