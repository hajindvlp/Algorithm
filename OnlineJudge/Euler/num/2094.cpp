#include <stdio.h>

int n, ans[21][3], x, y;

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d", &x, &y);
        if(x<y || (x+y)%2!=0)
            ans[i][1] = -1;
        else
        {
            ans[i][1] = (x+y)/2;
            ans[i][2] = x-ans[i][1];
        }
    }

    for(i=1 ; i<=n ; i++)
    {
        if(ans[i][1] == -1)
            printf("impossible\n");
        else
            printf("%d %d\n", ans[i][1], ans[i][2]);
    }
    return 0;
}
