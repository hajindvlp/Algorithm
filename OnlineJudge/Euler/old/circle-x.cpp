#include <stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))

int P[111][111];
int D[111][111];
int main()
{
    int N, s, e;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d%d", &s, &e);
        P[s][e] = P[e][s] = 1;
    }

    for (int i = 100; i > 0; --i)
    {
        for (int j = i + 1; j <= 100; ++j)
        {
            for (int k = i; k < j; ++k)
                D[i][j] = max(D[i][j], D[i][k] + D[k + 1][j - 1] + P[i][j]);
        }
    }
    printf("%d", D[1][100]);
    return 0;
}
