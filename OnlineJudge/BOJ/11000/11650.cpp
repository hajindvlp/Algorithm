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
        scanf("%d %d", &a[i].first, &a[i].second);
    
    sort(a+1, a+n+1);
    for(i=1 ; i<=n ; i++)
        printf("%d %d\n", a[i].first, a[i].second);

    return 0;
}