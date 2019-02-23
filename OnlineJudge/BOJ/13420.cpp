#include <stdio.h>

bool pro(long long int x, long long int op, long long int y, long long int z)
{
    if(op == '+' && x+y == z) return true;
    else if(op == '-' && x-y == z) return true;
    else if(op == '*' && x*y == z) return true;
    else if(op == '/' && x/y == z) return true;
    return false;
}

int main()
{
    int i, n;
    long long int x, y, z;
    char op;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%lld %c %lld = %lld", &x, &op, &y, &z);
        printf("%s\n", pro(x, op, y, z)?"correct":"wrong answer");
    }
    return 0;
}
