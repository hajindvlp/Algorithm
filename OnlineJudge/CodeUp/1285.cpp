#include <stdio.h>

int main()
{
    char op;
    int n, m;

    scanf("%d", &n);
    while(1)
    {
        scanf("%c", &op);
        if(op == '=')
            break;
        scanf("%d", &m);
        if(op == '+')
            n+=m;
        else if(op == '-')
            n-=m;
        else if(op == '*')
            n*=m;
        else
            n/=m;
    }
    printf("%d", n);
    return 0;
}
