#include <stdio.h>

int n, a[100001], cnt;

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &j), a[j]++;

    for(i=1 ; i<=100000 ; i++)
        if(a[i])
        {
            a[i]--;
            for(j=i/3*3 ; j<=i*2 ; j+=3)
                if(a[j-i])
                    cnt+=a[j-i], printf("%d %d\n", i, j-i);
            a[i]++;
        }
    printf("%d", cnt);
    return 0;
}
