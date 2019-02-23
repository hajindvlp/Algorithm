#include <stdio.h>
#include <algorithm>
using namespace std;

int n, d[4500001];

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &d[i]);
    sort(d+1, d+n+1);
    for(i=1 ; i<=n ; i++)
        printf("%d ", d[i]);
    return 0;
}
