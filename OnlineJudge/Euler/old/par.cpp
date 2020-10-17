#include <stdio.h>

int xcnt, ycnt;
int ans[3];
char a[52];

int main()
{
    int i, j;

    for(i=1 ; i<=2 ; i++)
    {
        scanf("%s", &a[1]);
        for(j=1 ; j<=50 ; j++)
        {
            if(a[j] == ')')
                xcnt++;
            else if(a[j] == '(')
                ycnt++;
            else
                break;
        }
        if(xcnt == ycnt)
            ans[i] = 1;
        xcnt = 0;
        ycnt = 0;
    }
    for(i=1 ; i<=2 ; i++)
    {
        if(ans[i])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
