#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 10000005;

int N, H, total;
int height [MAXN];

inline int binsearch (int value)
{
    int lo = 0, hi = N - 1, mid;

    while (lo < hi)
    {
        mid = (lo + hi + 1) >> 1;

        if (height [mid] <= value)
            lo = mid;
        else
            hi = mid - 1;
    }

    return lo;
}

int main ()
{
    scanf("%d %d", &N, &H);

    for (int i = 0; i < N; i++)
        scanf("%d", height + i);

    sort (height, height + N);

    total = 0;

    for (int i = 0; i < N; i++)
    {
        int ind = binsearch (H - height [i]);
        if (ind > i)
            total += ind - i;
        else break;
    }

    printf("%d", total);
    return 0;
}
