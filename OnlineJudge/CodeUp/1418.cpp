#include <stdio.h>
#include <string.h>

int main()
{
    char a[12];
    int i;

    scanf("%s", &a[1]);
    for(i=1 ; i<=strlen(&a[1]) ; i++)
        if(a[i] == 't')
            printf("%d ", i);

    return 0;
}
