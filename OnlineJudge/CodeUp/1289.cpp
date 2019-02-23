#include <stdio.h>

int main()
{
    int x, y, mx = 0, i;

    for(i=1 ; i<=3 ; i++)
    {
        scanf("%d %d", &x, &y);
        if(x*y>mx)
            mx = x*y;
    }
    printf("%d", mx);
    return 0;
}
