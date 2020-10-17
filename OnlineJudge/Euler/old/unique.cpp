#include <stdio.h>
#include <algorithm>
using namespace std;

int n, a[2000010];

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    for(i=1 ; i<=n ; i++)
        if(!(a[i-1] == a[i] || a[i] == a[i+1]))
        {
            printf("%d", a[i]);
            break;
        }
    return 0;
}
