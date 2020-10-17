#include <stdio.h>

int n, a[17], tmp[17], arr[17][17];

void isOk()
{
    int i;

    for(i=1 ; i<=n ; i++)
        if(a[i]<tmp[i])
            break;
    if(i!=n+1)
        for(i=1 ; i<=n ; i++)
            a[i] = tmp[i];
}

void dfs(int x, int y, int lev)
{
    if(lev == n)
        isOk();


}
