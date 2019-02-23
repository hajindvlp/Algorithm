#include <stdio.h>
#include <string.h>

int n, check[30];
char a[104];

int main()
{
    int i, j;

    scanf("%s", &a[1]);
    n = strlen(&a[1]);

    for(i='a'-'a'+1 ; i<='z'-'a'+1 ; i++)
        check[i] = -1;

    for(i=1 ; i<=n ; i++)
        if(check[a[i]-'a'+1] == -1)
            check[a[i]-'a'+1] = i-1;

    for(i=1 ; i<='z'-'a'+1 ; i++)
        printf("%d ", check[i]);

    return 0;
}