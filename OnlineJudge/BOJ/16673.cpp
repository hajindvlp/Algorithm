#include <stdio.h>

int main()
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    printf("%d", b*a*(a+1)/2+c*a*(a+1)*(a*2+1)/6);
    return 0;
}
