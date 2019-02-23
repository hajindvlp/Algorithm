#include <stdio.h>

int gcd(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = a % b;

        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    printf("%d", gcd(a, gcd(b, c)));
    return 0;
}
