#include <stdio.h>
#include <string.h>

int main()
{
    char a[1004];
    int n, i;

    scanf("%s", &a[1]);
    n = strlen(&a[1]);

    for(i=1 ; i<=n ; i++)
    {
        if(a[i]>='a' && a[i]<='z')
            printf("%c", a[i]-('a'-'A'));
        else if(a[i]>='A' && a[i]<='Z')
            printf("%c", a[i]+('a'-'A'));
        else
            printf("%c", a[i]);
    }
    return 0;
}
