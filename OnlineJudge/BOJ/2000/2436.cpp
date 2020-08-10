#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, i, c;

    scanf("%d %d", &a, &b);
    for(i=1 ; i<=(int)sqrt(b/a) ; i++)
        if((b/a)%i == 0)
            c = i;
    printf("%d %d", c*a, b/a/c*a);

}
