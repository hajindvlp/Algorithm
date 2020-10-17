#include <stdio.h>

int a[6][6], ans[6], tmp[6], acnt = 10000000, cnt;

void init()
{
    int i;

    cnt = 0;
    for(i=1 ; i<=5 ; i++)
        tmp[i] = 0;
}

int main()
{
    int i, j;

    for(i=1 ; i<=5 ; i++)
        for(j=1 ; j<=5 ; j++)
            scanf("%d", &a[i][j]);

    for(i=1 ; i<=5 ; i++)
    {
        for(j=1 ; j<=5 ; j++)
            if(a[i][j]>0)
            {
                cnt++;
                tmp[cnt] = a[i][j];
            }
        if(cnt<acnt)
        {
            for(j=1 ; j<=cnt ; j++)
                ans[j] = tmp[j];
            acnt = cnt;
        }
        init();

        for(j=1 ; j<=5 ; j++)
            if(a[j][i]>0)
            {
                cnt++;
                tmp[cnt] = a[j][i];
            }
        if(cnt<acnt)
        {
            for(j=1 ; j<=cnt ; j++)
                ans[j] = tmp[j];
            acnt = cnt;
        }
        init();
    }


    for(i=1 ; i<=5 ; i++)
        if(a[i][i]>0)
        {
            cnt++;
            tmp[cnt] = a[i][i];
        }
    if(cnt<acnt)
    {
        for(j=1 ; j<=cnt ; j++)
            ans[j] = tmp[j];
        acnt = cnt;
    }
    init();

    for(i=1 ; i<=5 ; i++)
        if(a[i][6-i]>0)
        {
            cnt++;
            tmp[cnt] = a[i][6-i];
        }
    if(cnt<acnt)
    {
        for(j=1 ; j<=cnt ; j++)
            ans[j] = tmp[j];
        acnt = cnt;
    }
    init();

    for(i=1 ; i<=acnt ; i++)
        printf("%d ", ans[i]);
    return 0;
}
