#include <stdio.h>

int n;

int main()
{
    int x, y;

    while(1)
    {
        scanf("%d %d", &x, &y);
        if(x == 0 && y == 0)
            break;
        printf("%d\n", x+y);
    }
    return 0;
}
