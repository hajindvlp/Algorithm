#include <stdio.h>

int n, m;
int used[11], make[7][7], heat[7][7], tmp;
int mxheat  = 500000;

void rec(int h, int bck)
{
    int i, cnt = 0;

    for(i=1 ; i<=n ; i++)
        if(used[i]!=0)
            cnt++;
    if(cnt == 1 && h<mxheat)
        mxheat = h;
    else
    {
        for(i=1 ; i<=m ; i++)
            if(used[i]!=0)
            {
                tmp = used[i];
                used[i] = make[bck][used[i]];
                rec(h+heat[bck][used[i]], i);
                used[i] = tmp;
            }
    }
}

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            scanf("%d %d", &make[i][j], &heat[i][j]);
    scanf("%d", &m);
    for(i=1 ; i<=m ; i++)
        scanf("%d", &used[i]);

    for(i=1 ; i<=m ; i++)
        rec(0, i);
}
