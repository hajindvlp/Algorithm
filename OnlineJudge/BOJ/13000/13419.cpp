#include <stdio.h>
#include <string.h>

void pro()
{
    char a[28], f[29], s[28];
    int fcnt, scnt;
    int i, len, tmp;

    for(i=1 ; i<=28 ; i++)
        f[i] = s[i] = a[i] = 0;
    fcnt = scnt = 0;

    scanf("%s", &a[1]);
    tmp = len = strlen(&a[1]);
    if(len%2==1)
        tmp*=2;

    for(i=1 ; i<=tmp ; i++)
    {
        if(i%2 == 1)
        {
            if(i%len == 0)
                f[++fcnt] = a[len];
            else
                f[++fcnt] = a[i%len];
        }
        else
        {
            if(i%len == 0)
                s[++scnt] = a[len];
            else
                s[++scnt] = a[i%len];
        }
    }

    printf("%s\n%s\n", &f[1], &s[1]);
}

int main()
{
    int i, n;
    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        pro();
}
