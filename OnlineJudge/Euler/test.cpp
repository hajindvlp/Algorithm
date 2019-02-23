#include <stdio.h>

char a[1001];//적당히 큰수

int strlen()
{
    int i;

    for(i=1 ; i<=1000 ; i++)
        if(a[i] == '\0')
            return i-1;
    return 0;
}

int main ()
{
    int n, i;

    scanf("%s", &a[1]);
    n = strlen();

    for(i=1 ; i<=n/2 ; i++)
        if(a[i]!=a[n-i+1])
        {
            printf("false palindrome");
            return 0;
        }
    printf("true palindrome");
    //palindrome : 회문 아마도...
    return 0;
}
