#include <stdio.h>

char word_list[38] = {0,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0'}, dic[101];

void output(int n)
{
    int i;

    for(i=1 ; i<=n ; i++)
        printf("%c", dic[i]);
    printf("\n");
}

void rec(int n, int max_len)
{
    int i;
    if(n == max_len)
        output(max_len);
    else
        for(i=1 ; i<=37 ; i++)
        {
            dic[n] = word_list[i];
            rec(n+1, max_len);
        }
}

int main()
{
    int n;

    scanf("%d", &n);
    rec(1, n);
    return 0;
}
