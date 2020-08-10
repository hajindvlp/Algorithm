#include <stdio.h>

void pro()
{
    int n, mx, a, sum;
    int i, j;

    scanf("%d", &n);

    sum = 0;
    for(i=1 ; i<=n ; i++)
    {
        mx = 0;
        for(j=1 ; j<=3 ; j++)
        {
            scanf("%d", &a);
            if(a>mx)
                mx = a;
        }
        sum+=mx;
    }

    printf("%d\n", sum);
}

int main()
{
    int n, i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        pro();
    return 0;
}
