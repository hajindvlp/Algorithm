#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m;
int a[5000001];

int main()
{
    int i;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);

    sort(a+1, a+n+1);
    printf("%d", a[m]);
    return 0;
}
