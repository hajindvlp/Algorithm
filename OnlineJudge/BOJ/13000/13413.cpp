#include <stdio.h>
#include <algorithm>
using namespace std;

int pro()
{
    int n, i, wcnt, bcnt;
    char ac[100001], bc[100001];
    wcnt = bcnt = 0;

    scanf("%d", &n);
    scanf("%s", &ac[1]);
    scanf("%s", &bc[1]);
    for(i=1 ; i<=n ; i++)
        if(ac[i] != bc[i])
        {
            if(ac[i] == 'B')
                bcnt++;
            else
                wcnt++;
        }

    printf("%d\n", min(bcnt, wcnt)+max(bcnt, wcnt)-min(bcnt, wcnt));
}

int main()
{
    int n, i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        pro();

    return 0;
}
