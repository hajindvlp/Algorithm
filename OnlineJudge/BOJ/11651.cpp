#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
pair<int, int>  a[100001];

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)   
        scanf("%d %d", &a[i].second, &a[i].first);
    
    sort(a+1, a+n+1);
    for(i=1 ; i<=n ; i++)
        printf("%d %d\n", a[i].second, a[i].first);

    return 0;
}