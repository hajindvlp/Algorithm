#include <stdio.h>

int pro()
{
    int x1, x2, x3, x4, y1, y2, y3, y4;
    int i, j;

    scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    if(((x1*y2 - x2*y1) + (x2*y3 - x3*y2) + (x3*y1 - x1*y3))*((x1*y2 - x2*y1) + (x2*y4 - x4*y2) + (x4*y1 - x1*y4))<0)
        return 0;
    return 1;
}


int main()
{
    printf("%d\n%d", pro(), pro());
    return 0;
}
