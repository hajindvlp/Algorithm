#include <stdio.h>

int main()
{
    char a[101];
    int n, m, i;

    scanf("%s %d %d", a, &n, &m);
    for(i=n ; i<=n+m-1 ; i++)
        printf("%c", a[i]);
    return 0;
}
