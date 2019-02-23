#include <stdio.h>
#define INF 100000000

int n, m;
int a[201], cnt[2000001], d[2000001];

int main()
{
    int i, j = 0;

    scanf("%d %d", &m, &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);

    cnt[0] = 0;
    while(1)
    {
        j++;
        cnt[j] = INF;
        for(i=1 ; i<=n ; i++)
            if(j-a[i]>=0 && cnt[j-a[i]]+1<=m && cnt[j-a[i]]+1<cnt[j])
                d[j] = 1, cnt[j] = cnt[j-a[i]]+1;
        if(cnt[j] == INF)
            break;
    }
    printf("%d", j-1);
    return 0;
}
