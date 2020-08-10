#include <stdio.h>

int cnt;

int main()
{
    int n;

    scanf("%d", &n);
    while(n)
    {
        cnt+=n/5;
        n%=5;
        if(n<5)
            break;
    }

    printf("%d", cnt);
}
