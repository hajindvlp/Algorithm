#include <stdio.h>

int n, a[101][101];
long long int d[101][101];

int pro()
{
    int i, j;
    char s[105];

    scanf("%d", &n);

    if(n == -1) return 0;

    for(i=1 ; i<=n ; i++) {
        scanf("%s", &s[1]);
        for(j=1 ; j<=n ; j++) a[i][j] = s[j] - '0', d[i][j] = 0;
    }

    d[1][1] = 1;
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            if(d[i][j]!=0)
            {
                if(i == n && j == n) continue;
                if(i+a[i][j]<=n)
                    d[i+a[i][j]][j]+=d[i][j];
                if(j+a[i][j]<=n)
                    d[i][j+a[i][j]]+=d[i][j];
            }

    printf("%lld\n", d[n][n]);
    return 1;
}

int main() {
    while(pro());
}