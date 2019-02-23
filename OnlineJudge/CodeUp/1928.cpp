#include <stdio.h>

void rec(int x)
{
    printf("%d\n", x);
    if(x == 1)
        return;
    if(x%2 == 1)
        rec(3*x+1);
    else
        rec(x/2);
}

int main()
{
    int n;
    scanf("%d", &n);
    rec(n);
}
