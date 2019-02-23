#include <stdio.h>
#include <string.h>

char a[32], b[32], n, m;
int cnt[201];

int main()
{
    int i, j;
    int alen, blen;

    scanf("%s %s", &a[1], &b[1]);
    alen = strlen(&a[1]);
    blen = strlen(&b[1]);
    for(i=1 ; i<=alen ; i++)
    {
        for(j=1 ; j<=blen ; j++)
            if(a[i] == b[j])
            {
                m = i;
                n = j;
                break;
            }
        if(j<=blen)
            break;
    }

    for(i=1 ; i<=blen ; i++)
    {
        if(i == n)
            for(j=1 ; j<=alen ; j++)
                printf("%c", a[j]);
        else
            for(j=1 ; j<=alen ; j++)
            {
                if(j == m)
                    printf("%c", b[i]);
                else
                    printf(".");
            }
        printf("\n");
    }
    return 0;
}
