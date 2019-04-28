#include <stdio.h>
int n, dp[10001] = { 1, 0, 3 };

int main()
{
    scanf("%d", &n);
    for(int i = 4; i <= n; ++i)
    {
        dp[i] = 3 * dp[i - 2];
        for (int j = 4; j <= i; j += 2)
            dp[i] += 2 * dp[i - j];
    }
    printf("%d\n", dp[n]);
    return 0;
}
