#include <stdio.h>
#define abs(x) (x>0 ? x:-x)

int main()
{
    double d;

    scanf("%lf", &d);
    printf("%g", abs(d));
    return 0;
}
