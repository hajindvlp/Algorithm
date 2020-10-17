#include <stdio.h>
#include <algorithm>
using namespace std;

int n, a[10001];

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    printf("%d", a[(n+1)/2]);
}
