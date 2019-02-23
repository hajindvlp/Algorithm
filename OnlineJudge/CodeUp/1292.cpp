#include <stdio.h>

char a[12];

int main()
{
    int i, sum = 0;

    scanf("%s", &a[1]);
    for(i=1 ; i<=10 ; i++)
        sum+=a[i]-'0';

    if(sum%7 == 4)
        printf("suspect");
    else
        printf("citizen");
    return 0;
}
