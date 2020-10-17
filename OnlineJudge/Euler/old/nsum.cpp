#include <stdio.h>

int n, sum;

int main()
{
    int i;

    scanf("%d", &n);
    if(n<0)
        n=-n;
    for(i=1 ; i<=44723 ; i++)
    {
        sum+=i;
        if(sum>=n && (sum-n)%2 == 0)
        {
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}
