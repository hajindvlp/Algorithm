#include <stdio.h>

int n;

int cal(int x)
{
    return x*x-x+1;
}

int main()
{
    int i, j, x;

    for(i=1 ; i<=5 ; i++)
    {
        j = 1;
        scanf("%d", &x);
        while(!(cal(j+1)>=x && x>=cal(j)))
            j++;

        if(j%2 == 0)
        {
            if(x-cal(j)<j)
                printf("%d %d\n", j, j-x+cal(j));
            else
                printf("%d %d\n", j+1, j+1-(cal(j+1)-x));
        }
        else
        {
            if(x-cal(j)<j)
                printf("%d %d\n", j-x+cal(j), j);
            else
                printf("%d %d\n", j+1-(cal(j+1)-x), j+1);
        }
    }
}
