#include <stdio.h>

int main()
{
    int cnt = 0, i, j;
    char tmp[10];

    for(i=1 ; i<=8 ; i++)
    {
        scanf("%s", &tmp[1]);
        for(j=1 ; j<=8 ; j++)
            if(tmp[j] == 'F' && (i+j)%2 == 0)
                cnt++;
    }
    printf("%d", cnt);
}
