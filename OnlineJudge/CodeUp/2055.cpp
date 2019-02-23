#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int a[70001], cnt, check[32000];

int main()
{
    int x, y;
    int i;

    scanf("%d %d", &x, &y);
    for(i=1 ; i<=32000 && (i<=sqrt(x) || i<=sqrt(y)); i++)
        if(check[i] == 0)
        {
            if(x%i == 0)
            {
                check[i] = 1;
                a[++cnt] = i, a[++cnt] = x/i;
            }
            if(y%i == 0)
            {
                if(check[i] == 0)
                    a[++cnt] = i, check[i] = 1;
                a[++cnt] = y/i;
            }
        }

    sort(a+1, a+cnt+1);
    for(i=1 ; i<=cnt ; i++)
        printf("%d ", a[i]);
    return 0;
}
