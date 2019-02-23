#include <stdio.h>
#include <algorithm>
using namespace std;

int a[101], n;

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);

    sort(a+1, a+n+1);
    for(i=n ; i>=1 ; i--)
        printf("%d ", a[i]);
    return 0;
}
