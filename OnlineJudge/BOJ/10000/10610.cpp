#include <stdio.h>
#include <string.h>

int n;
int count[10], sum;
char a[100000];

int main()
{
    int i, j;

    scanf("%s", &a[1]);
    n = strlen(&a[1]);

    for(i=1 ; i<=n ; i++)
        sum+=a[i]-'0', count[a[i]-'0']++;
    if(sum%3 == 0 && count[0]!=0)
        for(i=9 ; i>=0 ; i--)
            for(j=1 ; j<=count[i] ; j++)
                printf("%d", i);
    else
        printf("-1");
}
