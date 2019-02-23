#include <cstdio>

#define max(a, b, c) (a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c))

int sticker[2][100000] = { 0 };
int dp[3][100000] = { 0 };

int main()
{
    int t;

    for(scanf("%d", &t); t > 0; t--)
    {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
                scanf("%d", &sticker[i][j]);
        }

        dp[0][0] = 0;
        dp[1][0] = sticker[0][0];
        dp[2][0] = sticker[1][0];

        for (int i = 1; i < n; ++i)
        {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]);
            dp[1][i] = (max(dp[0][i - 1], 0, dp[2][i - 1])) + sticker[0][i];
            dp[2][i] = (max(dp[0][i - 1], dp[1][i - 1], 0)) + sticker[1][i];
        }

        printf("%d\n", max(dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]));
    }

    return 0;
}
