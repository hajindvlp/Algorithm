#include <stdio.h>

int main()
{
    int a, b, cnt = 0;
    int i;

    scanf("%d %d", &a, &b);
    for(i=a ; i<=b ; i++)
    {
        int tmp = i;
        while(1)
        {
            if(tmp%2 == 1)
                break;
            cnt++;
            tmp/=2;
        }
    }
    printf("%d", cnt);
}
