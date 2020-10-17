#include <stdio.h>
#include <string.h>

char c[20];
int n;

int main()
{
    int i, j;

    scanf("%s", &c[1]);
    n = strlen(&c[1]);

    printf(".");
    for(i=1 ; i<=n ; i++)
    {
        if(i%3 != 0)
            printf(".#..");
        else
            printf(".*..");
    }
    printf("\n");


    printf(".");
    for(i=1 ; i<=n ; i++)
    {
        if(i%3 == 0)
            printf("*.*.");
        else
            printf("#.#.");
    }
    printf("\n");

    printf("#");
    for(i=1 ; i<=n ; i++)
    {
        if(i%3 == 0)
            printf("*.%c.*", c[i]);
        else if((i+1)%3 == 0)
            printf(".%c.", c[i]);
        else if((i-1)%3 == 0)
            printf(".%c.#", c[i]);
    }
    if(n%3==2)
        printf("#");
    printf("\n");


    printf(".");
    for(i=1 ; i<=n ; i++)
    {
        if(i%3 == 0)
            printf("*.*.");
        else
            printf("#.#.");
    }
    printf("\n");

    printf(".");
    for(i=1 ; i<=n ; i++)
    {
        if(i%3 != 0)
            printf(".#..");
        else
            printf(".*..");
    }
    return 0;
}
