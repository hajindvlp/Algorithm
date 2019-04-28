#include <stdio.h>

int mn(int a, int b)
{
    return (a>b?b:a);
}

int main()
{
    int sy, sx, w, h;
    int ans;

    scanf("%d %d %d %d", &sy, &sx, &h, &w);
    ans = h-sy;
    ans = mn(ans, sy);
    ans = mn(ans, w-sx);
    ans = mn(ans, sx);
    printf("%d", ans);
}
