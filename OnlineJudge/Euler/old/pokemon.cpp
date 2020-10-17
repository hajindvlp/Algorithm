#include <stdio.h>

int n;
char name[71][22];
int ans, ansflag, sum, mx;

int main()
{
    int i, j;
    int x, y, cnt;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        cnt = 0;
        scanf("%s", &name[i][1]);
        scanf("%d %d", &x, &y);
        for(j=y ; j>0 ; j-=x)
        {
            cnt++;
            j+=2;
        }
        if(cnt>mx)
            mx = cnt, ansflag = i;
        sum += cnt-1;
    }

    printf("%d\n", sum);
    printf("%s", &name[ansflag][1]);
    return 0;
}
