#include <stdio.h>
#include <string.h>

int len, c[10];
char a[11];

int main()
{
    int i, j;

    scanf("%s", &a[1]);
    len = strlen(&a[1]);

    for(i=1 ; i<=len ; i++)
        c[a[i]-'0']++;

    for(i=9 ; i>=0 ; i--)
        for(j=1 ; j<=c[i] ; j++)
            printf("%d", i);

    return 0;
}
