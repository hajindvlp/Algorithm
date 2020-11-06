#include <stdio.h>
#include <iostream>
#include <math.h>

int x, y, sum;

int main()
{
    char c, tmp;

    while(getc(stdin) == ' ')
    {
        scanf("%c", c);
        sum = 0;
        if(c == '\n')
            break;
        else if(c == 'n')
        {
            scanf("%c", &tmp), tmp-='0';
            sum+=tmp*10;
            scanf("%c", &tmp), tmp-='0';
            sum+=tmp;
            y+=sum;
        }
        else if(c == 's')
        {
            scanf("%c", &tmp), tmp-='0';
            sum+=tmp*10;
            scanf("%c", &tmp), tmp-='0';
            sum+=tmp;
            y-=sum;
        }
        else if(c == 'e')
        {
            scanf("%c", &tmp), tmp-='0';
            sum+=tmp*10;
            scanf("%c", &tmp), tmp-='0';
            sum+=tmp;
            x+=sum;
        }
        else if(c == 'e')
        {
            scanf("%c", &tmp), tmp-='0';
            sum+=tmp*10;
            scanf("%c", &tmp), tmp-='0';
            sum+=tmp;
            x-=sum;
        }
    }

    printf("%d %d ", x, y);

    printf("%lf", sqrt(pow(x, 2)+pow(y, 2)));
    return 0;
}
