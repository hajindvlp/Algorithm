#include <stdio.h>

int n, a, b, ans[1001][2];

int gcd(int x, int y)
{
    if(y == 0)
        return x;
    else
        return gcd(y, x%y);
}

int lcm(int x, int y){
    return x * y / gcd(x,y);
}

int main()
{
    int i, x;

    scanf("%d", &n);

    scanf("%d", &a);
    for(i=2 ; i<=n ; i++)
    {
        scanf("%d", &b);
        x = lcm(a, b);
        ans[i][0] = x/b;
        ans[i][1] = x/a;
    }
    for(i = 2 ; i<=n ; i++)
        printf("%d/%d\n", ans[i][0], ans[i][1]);
    return 0;
}
