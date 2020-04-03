#include <stdio.h>

int n, a[100005];
int cnt, mx;

int main() {
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++) scanf("%d", &a[i]);

    for(i=n ; i>=1 ; i--)
        if(mx<a[i]) {
            cnt++;
            mx = a[i];
        }

    printf("%d", cnt);
}