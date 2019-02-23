#include <stdio.h>

int n, a[1000001][3], b[1000001][3];

int main()
{
    int i, j, cnt = 0, tmp = 1 ,x, y, start;
    int incnt, outcnt, mx = 1000000000, my = 1000000000;
    int acnt = 0, bcnt = 0;

    scanf("%d", &n);

    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d", &a[i][1], &a[i][2]);
        if(a[i][1]<mx && a[i][2]<my)
        {
            mx = a[i][1];
            my = a[i][2];
            start = i;
        }
    }
    for(i = start ; i<=n ; i++)
    {
        b[i-start+1][1] = a[i][1];
        b[i-start+1][2] = a[i][2];
    }
    for(i=1 ; i<start ; i++)
    {
        b[i+n-start+1][1] = a[i][1];
        b[i+n-start+1][2] = a[i][2];
    }

    for(i=1 ; i<=n ; i++)
        a[i][1] = a[i][2] = 0;
    for(i=1 ; i<=n ; i++)
    {
        x = b[i][1];
        y = b[i][2];
        if(y<0 && cnt == 0)
        {
            cnt++;
            a[tmp][1] = x;
        }
        else if(y>0 && cnt == 1)
            cnt++;
        else if(y<0 && cnt == 2)
        {
            cnt = 0;
            a[tmp][2] = x;
            tmp++;
        }
    }

    for(i=1 ; i<=tmp ; i++)
    {
        incnt = outcnt = 0;
        for(j=1 ; j<=tmp ; j++)
            if(j!=i)
            {
                if(a[i][1]>a[j][1] && a[i][2]<a[j][2])
                    outcnt++;
                else if(a[i][1]<a[j][1] && a[i][2]>a[j][2])
                    incnt++;
            }
        if(outcnt == 0)
            acnt++;
        if(incnt == 0)
            bcnt++;
    }
    printf("%d %d", acnt, bcnt);
    return 0;
}
