#include <stdio.h>

void pro()
{
    int n, i;

    scanf("%d", &n);
    for(i=1 ; i*i<=n ; i++);
    printf("%d\n", i-1);
}

int main()
{
    int t;

    scanf("%d", &t);
    while(t--){pro();}
    return 0;
}
