#include <stdio.h>

int n, a[1001][6], check[1001][1001];
int ans, cnt, mx = -1;

int main()
{
    int i, j, k;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=5 ; j++)
            scanf("%d", &a[i][j]);

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            for(k=1 ; k<=5 ; k++)
                if(i!=j && a[i][k] == a[j][k])
                    check[i][j] = 1, check[j][i] = 1;

    for(i=1 ; i<=n ; i++)
    {
        cnt = 0;
        for(j=1 ; j<=n ; j++)
            cnt+=check[i][j];
        if(cnt>mx)
            mx = cnt, ans = i;
    }
    printf("%d", ans);
    return 0;
}
