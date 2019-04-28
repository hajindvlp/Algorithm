#include <stdio.h>

int a[11], mn, mul[11], n;

void rec(int lev, int s, int m)
{
    if(lev == 5)
    {
        if(mn<m && s == n+1)
            mn = m;
        return;
    }
    for(i=s ; i<=n-(4-lev) ; i++)
}
