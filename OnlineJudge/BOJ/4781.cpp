#include <stdio.h>

bool pro()
{
    int n, m, d[10001];
    int i, j;
    int m1, m2;
    int p, c;

    for(i=0 ; i<=10000 ; i++)
        d[i] =  0;

    scanf("%d %d.%d", &n, &m1, &m2);
    if(n == 0)
        return false;
    m = m1*100+m2;

    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d.%d", &c, &m1, &m2);
        p = m1*100+m2;
        for(j=p ; j<=m ; j++)
            if(d[j]<d[j-p]+c)
                d[j]=d[j-p]+c;
    }

    printf("%d\n", d[m]);
    return true;
}

int main()
{
    while(pro());
}
