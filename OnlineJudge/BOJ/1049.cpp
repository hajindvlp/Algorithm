#include <stdio.h>

int a = 10000, b = 10000, n, m;
int x, y;

int main()
{
    int i;

    scanf("%d %d", &m, &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d", &x, &y);
        if(a>x)
            a = x;
        if(b>y)
            b = y;
    }
    if(a>b*6)
        a = b*6;

    printf("%d", ((m/6)*a+a>(m/6)*a+(m%6)*b)?(m/6)*a+(m%6)*b:(m/6)*a+a);
}
