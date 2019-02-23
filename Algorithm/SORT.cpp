#include <stdio.h>
#include <algorithm>
using namespace std;

int a[10001], n;

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);
        
    sort(a+1, a+n+1);
}
