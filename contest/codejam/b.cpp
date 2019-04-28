#include <stdio.h>
#include <string.h>

void pro()
{
    char a[1001][53];
    int n, i, j;
    int cnt = 0, len, alen;
    cnt = 0;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%s", &a[i][1]);
        alen = strlen(&a[i][1]);
        for(j=1 ; j<=i-1 ; j++)
        {
            len = strlen(&a[j][1]);
            if(a[j][len-1] == a[i][alen-1] && a[j][len] == a[i][alen])
                cnt++;
        }
    }

    printf("%d", cnt);
}

int main()
{
    int t;

    scanf("%d", &t);
    while(t--)
        pro();
}
