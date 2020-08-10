#include <stdio.h>

int d[5001];
char tmp[5001];

int main()
{
    int i;

    scanf("%s", tmp);

    d[0] = 1;
    for(i=0 ; tmp[i] ; i++)
    {
        tmp[i] -= '0';
        if(tmp[i])
        {
            d[i+1]+=d[i]%1000000;
            if(tmp[i]*10+tmp[i+1]-'0'<=26)
                d[i+2] += d[i]%1000000;
        }
    }
    printf("%d", d[i]%1000000);
    return 0;
}
