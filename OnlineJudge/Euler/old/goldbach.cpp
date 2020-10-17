#include <stdio.h>

int n, cnt;
int a[30001];

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=3 ; i<=n ; i++)
        if(a[i] == 0)
            for(j=i*i ; j<=n ; j+=i)
                a[j] = 1;

    for(i=3 ; i<=n/2 ; i+=2)
        if(a[i] == 0 && a[n-i] == 0)
            printf("%d %d\n", i, n-i), cnt++;

    printf("%d", cnt);
    return 0;
}
