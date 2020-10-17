#include <stdio.h>

int n, cnt = 1, tmp, sum;

int main()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        tmp++;
        sum+=cnt;
        if(tmp == cnt)
        {
            tmp = 0;
            cnt++;
        }
    }
    printf("%d", sum);
}
