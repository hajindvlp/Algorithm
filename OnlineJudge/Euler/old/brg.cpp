#include <stdio.h>

int n, sum;
char tmp[15];

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%s", &tmp[1]);
        for(j=1 ; j<=13 ; j++)
        {
            if(tmp[j] == 'A')
                sum+=4;
            else if(tmp[j] == 'K')
                sum+=3;
            else if(tmp[j] == 'Q')
                sum+=2;
            else if(tmp[j] == 'J')
                sum++;
        }
    }

    printf("%d", sum);
    return 0;
}
