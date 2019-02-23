#include <stdio.h>

int main()
{
    int mx =-1000001, mn = 1000001, x, i;

    for(i=1 ; i<=5 ; i++)
    {
        scanf("%d", &x);
        if(x>mx)
            mx = x;
        if(x<mn)
            mn = x;
    }
    printf("%d\n%d", mx, mn);
}
