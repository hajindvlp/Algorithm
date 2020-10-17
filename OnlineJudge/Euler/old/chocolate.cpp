#include <stdio.h>

int x, y;

int main()
{
    scanf("%d %d", &x, &y);
    if((x*y+1)%2 == 0)
        printf("2");
    else    
        printf("1");

    return 0;
}