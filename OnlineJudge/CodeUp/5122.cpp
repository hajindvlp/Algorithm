#include <stdio.h>
#define ABS(N) ((N<0)?(-N):(N))

int mx = 10000000;
int sum, x, y, amx, bmx, n;
bool lef, rig;

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d", &x, &y);
        if(ABS(x-y)<mx) mx = ABS(x-y), amx = x, bmx = y;
        if(x>y) sum+=x, lef = true;
        else sum+=y, rig = true;
    }

    if(rig&&lef) printf("%d", sum);
    else if(!rig) printf("%d", sum-amx+bmx);
    else if(!lef) printf("%d", sum-bmx+amx);
    return 0;
}
