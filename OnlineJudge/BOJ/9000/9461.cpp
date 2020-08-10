#include <stdio.h>

int n, t;
long long int a[101];

void pro()
{
    int i;

    a[0] = a[1] = a[2] = a[3] = 1;
    a[4] = a[5] = 2;
    for(i=6 ; i<=100 ; i++)
        a[i] = a[i-1]+a[i-5];
}

int main()
{
    pro();
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%lld\n", a[n]);
    }
    return 0;
}
