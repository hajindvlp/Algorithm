#include <stdio.h>
#define MOD 1000000009
int d[1000005];

void pro() {
    int n;
    scanf("%d", &n);
    printf("%d\n", d[n]);            
}

int main() {
    int T;
    int i, j;

    scanf("%d", &T);

    d[0] = 1;
    for(i=1 ; i<=1000000 ; i++) {
        for(j=1 ; j<=3 ; j++) 
            if(i-j >= 0) 
                d[i] = (d[i] + d[i-j]) % MOD;
    }

    while(T--) pro();

    return 0;
}