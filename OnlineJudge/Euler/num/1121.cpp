#include <stdio.h>
#include <algorithm>
using namespace std;

int n, sum, x, y, z;

int main()
{
    int i;

    scanf("%d %d", &n, &z);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d", &x, &y);
        if(abs(x-y)>z)
            scanf("%d", &x), sum+=x;
        else
            sum+=max(x, y);
    }
    printf("%d", sum);
    return 0;
}
