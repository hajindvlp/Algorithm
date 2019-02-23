#include <stdio.h>

int n, a[20001][3], cnt, visit[20001];

int main()
{
    int i, j, x, y, w, h;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d %d %d", &x, &y, &w, &h);
        for(j=x ; j<=x+w-1 ; j++)
        {
            if(a[j][1]>y || visit[j] == 0)
                a[j][1] = y, visit[j] = 1;
            if(a[j][2]<y+h-1)
                a[j][2] = y+h-1;
        }
    }

    for(i=0 ; i<=20000 ; i++)
        if(a[i][1]!=0 || a[i][2]!=0)
            cnt+=(a[i][2]-a[i][1]+1);

    printf("%d", cnt);
    return 0;
}
