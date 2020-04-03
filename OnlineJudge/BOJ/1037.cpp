#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int n, i, x;
    int mn = 1000005, mx = 0;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++) {
        scanf("%d", &x);
        mn = min(mn, x), mx = max(mx, x);
    }

    unsigned long long int ans = mn * mx;

    printf("%llu", ans);
}
