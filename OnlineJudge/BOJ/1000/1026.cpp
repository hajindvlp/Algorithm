#include <stdio.h>
#include <algorithm>
using namespace std;

int a[51], b[51], n, mn;

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++) scanf("%d", &a[i]);
    for(i=1 ; i<=n ; i++) scanf("%d", &b[i]);
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    for(i=1 ; i<=n ; i++) mn += a[i]*b[n-i+1];
    printf("%d", mn);
}
