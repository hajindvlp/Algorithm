#include <stdio.h>
#include <math.h>

void pro()
{
    int i, cnt;
    int x, y, r, sx, sy, ex, ey, n;

    cnt = 0;
    scanf("%d %d %d %d %d", &sx, &sy, &ex, &ey, &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d %d", &x, &y, &r);
        if(sqrt(pow(x-sx, 2)+pow(y-sy, 2))<=r || sqrt(pow(x-ex, 2)+pow(y-ey, 2))<=r)
            cnt++;
    }
    printf("%d\n", cnt);
}

int main()
{
    int t;

    scanf("%d", &t);
    while(t--)
        pro();
    return 0;
}
