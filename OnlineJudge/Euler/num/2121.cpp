#include <stdio.h>

int a[11], b[11], acnt, bcnt;

int main()
{
    int i;
    int best = -1;

    for(i=1 ; i<=10 ; i++)
        scanf("%d", &a[i]);
    for(i=1 ; i<=10 ; i++)
        scanf("%d", &b[i]);

    for(i=1 ; i<=10 ; i++)
    {
        if(a[i]>b[i])
        {
            acnt+=3;
            best = 1;
        }
        else if(a[i] == b[i])
        {
            acnt++;
            bcnt++;
        }
        else
        {
            bcnt+=3;
            best = 0;
        }
    }

    printf("%d %d\n", acnt, bcnt);
    if((acnt == bcnt && best == 1) || acnt>bcnt)
        printf("A");
    else if((acnt == bcnt && best == 0) || acnt<bcnt)
        printf("B");
    else if((acnt == bcnt && best == -1))
        printf("D");
    return 0;
}
