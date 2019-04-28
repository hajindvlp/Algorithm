#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int num, cnt;
int inNum[5], targetNum[5], inNumCnt[10], targetNumCnt[10];

int main()
{
    int i, j;
    int scnt, bcnt;
    srand(time(NULL));

    targetNum[1] = rand()%9+1;
    targetNumCnt[targetNum[1]] = 1;
    for(i=2 ; i<=4 ; i++)
    {
        targetNum[i] = rand()%10;
        while(targetNumCnt[targetNum[i]])
            targetNum[i] = rand()%10;
        targetNumCnt[targetNum[i]] = 1;

    }

    while(scnt != 4)
    {
        cnt++;
        scnt = bcnt = 0;

        for(i=0 ; i<=9 ; i++)
            inNumCnt[i] = 0;

        for(i=1 ; i<=4 ; i++)
            scanf("%1d", &inNum[i]), inNumCnt[inNum[i]] = 1;
        if(inNum[1] == 0)
            break;

        for(i=1 ; i<=4 ; i++)
            if(inNum[i] == targetNum[i])
                scnt++, inNumCnt[inNum[i]] = 0;

        for(i=0 ; i<=9 ; i++)
            if(inNumCnt[i] && targetNumCnt[i])
                bcnt++;

        if(bcnt == 0 && scnt == 0)
            printf("OUT\n");
        else
            printf("Strike : %d\nBall : %d\n", scnt, bcnt);
    }

    printf("wow correct\nThe answer was : ");
    for(i=1 ; i<=4 ; i++)
        printf("%d", targetNum[i]);
    printf("\n");
    printf("you got the answer by %dtimes", cnt);
}
