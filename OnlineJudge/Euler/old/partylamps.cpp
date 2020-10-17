#include <stdio.h>
#include <string.h>

int n, m, yes[101], no[101], yn, nn;
char ansString[10001][102];
bool p[5], tmp[101];
int ans;

void rec(int lev)
{
    int i, cnt = 0;
    bool x, y;

    if(lev == 0)
    {
        cnt = 0;
        for(i=1 ; i<=4 ; i++)
            cnt+=p[i];

        if((m-cnt)%2 == 0 && m-cnt>=0)
        {
            for(i=1 ; i<=n ; i++)
                tmp[i] = true;

            if(p[1])
                for(i=1 ; i<=n ; i++)
                    tmp[i] = !tmp[i];
            if(p[2])
                for(i=2 ; i<=n ; i+=2)
                    tmp[i] = !tmp[i];
            if(p[3])
                for(i=1 ; i<=n ; i+=2)
                    tmp[i] = !tmp[i];
            if(p[4])
                for(i=1 ; i<=n ; i+=3)
                    tmp[i] = !tmp[i];

            x = true;
            for(i=1 ; i<=yn-1 ; i++)
                if(!tmp[yes[i]])
                    x = false;

            y = true;
            for(i=1 ; i<=nn-1 ; i++)
                if(tmp[no[i]])
                    y = false;

            if(x&&y)
            {
                ans++;
                for(i=1 ; i<=n ; i++)
                    ansString[ans][i] = tmp[i]+'0';
            }
        }
    }
    else
    {
        p[lev] = false;
        rec(lev-1);
        p[lev] = true;
        rec(lev-1);
    }
}

void swap(int x, int y)
{
    char tmp[102];
    int i;

    for(i=1 ; i<=n ; i++)
        tmp[i] = ansString[x][i];
    for(i=1 ; i<=n ; i++)
        ansString[x][i] = ansString[y][i];
    for(i=1 ; i<=n ; i++)
        ansString[y][i] = tmp[i];
}

int main()
{
    int i, j;

    scanf("%d %d", &n, &m);
    while(yes[yn] != -1)
    {
        yn++;
        scanf("%d", &yes[yn]);
    }
    while(no[nn] != -1)
    {
        nn++;
        scanf("%d", &no[nn]);
    }

    rec(4);

    for(i=1 ; i<=ans-1 ; i++)
        for(j=i ; j<=ans ; j++)
            if(strcmp(&ansString[i][1], &ansString[j][1])==1)
                swap(i, j);

    for(i=1 ; i<=ans ; i++)
    {
        for(j=1 ; j<=n ; j++)
            printf("%c", ansString[i][j]);
        printf("\n");
    }

    if(ans == 0)
        printf("IMPOSSIBLE");
    return 0;
}
