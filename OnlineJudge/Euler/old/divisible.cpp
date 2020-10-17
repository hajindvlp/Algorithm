#include <stdio.h>

int a[100001], n, m, d[100001];
bool ans[4];

int abs(int x)
{
    if(x<0)
        return -x;
    else
        return x;
}

bool pro()
{
    int i, j, mx = 0, x;

    scanf("%d %d", &n, &m);

    for(i=1 ; i<=100000 ; i++)
    {
        a[i] = 0;
        d[i] = 0;
    }

    for(i=1 ; i<=n ; i++)
    {
        scanf("%d", &x);
        a[i] = x%m;
    }

    for(i=1 ; i<=n ; i++)
    {
        for(j=0 ; j<=mx ; j++)
            if(d[j] == i-1)
            {
                d[abs(j-a[i])] = i;
                d[abs(j+a[i])] = i;
                if(abs(j+a[i])%m == 0 || abs(j-a[i])%m == 0)
                    return true;
            }
        mx+=abs(a[i]);
    }
    return false;
}

int main()
{
    int i;

    for(i=1 ; i<=3 ; i++)
        ans[i] = pro();
    for(i=1 ; i<=3 ; i++)
    {
        if(ans[i])
            printf("Divisible\n");
        else
            printf("Not divisible\n");
    }
    return 0;
}
