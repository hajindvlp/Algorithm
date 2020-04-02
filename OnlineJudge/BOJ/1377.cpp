#include <stdio.h>
#include <algorithm>
using namespace std;

int n, ans;
pair<int, int> a[500001];

int main() {
    int i, x;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++) scanf("%d", &x), a[i] = make_pair(x, i);
    sort(a+1, a+n+1);
    
    for(i=1 ; i<=n ; i++) 
        ans = max(ans, a[i].second - i);

    printf("%d", ans+1);
}