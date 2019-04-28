#include <stdio.h>

int main()
{
    int cnt = 0, n;

    scanf("%d", &n);
    while(n)
        cnt+=n%2, n/=2;
    printf("%d", cnt);
}
