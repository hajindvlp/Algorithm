#include <stdio.h>

int n, a[1001][3];
int b[1001], l[1001], blen, oldb[1001];
int d[1001][1001];
int mx;

int abs(int x)
{
    if(x<0)
        return -x;
    return x;
}

int main()
{
    int i, j, k, tmp;

    scanf("%d", &n);

    b[1] = 0;
    blen = 1;

    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d", &l[1], &l[2]);
        for(j=1 ; j<=2 ; j++)
        {
            mx = 1000000000;
            for(k=1 ; k<=blen ; k++)
                if(abs(b[k]-l[j])+d[i-1][k]<mx)
                    mx = abs(b[k]-l[j])+d[i-1][k];
            d[i][j] = mx;
        }
        for(j=1 ; j<=blen ; j++)
            oldb[j] = b[j];
        tmp = blen;
        blen = 2;
        for(j=1 ; j<=tmp ; j++)
            if(oldb[j]>l[2] || oldb[j]<l[1])
                b[++blen] = oldb[j], d[i][blen] = d[i-1][j];
        b[1] = l[1], b[2] = l[2];
    }

    mx = 1000000000;
    for(i=1 ; i<=blen ; i++)
    {
        if(abs(b[i])+d[n][i]<mx)
            mx = abs(b[i])+d[n][i];
    }

    printf("%d\n", mx+n+1);
    return 0;
}