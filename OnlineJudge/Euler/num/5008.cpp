#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1001], b[1001], sum, n, tmp;

void pro()
{
    int i;
    sum = 0, tmp = 0;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]), b[i] = a[i];

    sort(a+1, a+n+1);
    for(i=1 ; i<=n ; i++)
        if(a[i]!=b[i])
        {
            if(tmp == 0)
                tmp = a[i];
            sum+=b[i];
        }
    printf("%d\n", sum+tmp);
}

int main()
{
    pro(), pro();
    return 0;
}
