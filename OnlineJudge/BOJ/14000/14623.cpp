#include <stdio.h>

int main() {
    int a[2], i, j;
    char s[33];

    for(i=1 ; i<=2 ; i++) {
        a[i] = 0;
        scanf("%s", &s[1]), j=1;
        while(s[j]) {
            a[i] = 2*a[i] + s[j]-'0';
            j++;
        }
    }
    long long int mult = a[1]*a[2];
    int ans[66], cnt = 0;
    while(mult) {
        ans[++cnt] = mult%2;
        mult/=2;
    }
    for(i=cnt ; i>=1 ; i--) printf("%d", ans[i]);
}