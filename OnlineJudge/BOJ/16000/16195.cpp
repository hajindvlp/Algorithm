#include <stdio.h>
#define MOD 1000000009


int d[1001][1001];

int main() {
    int T;
    int i, j, k, x, y, sum;

    d[0][0] = 1;
    for(i=1 ; i<=1000 ; i++) 
        for(j=1 ; j<=1000 ; j++) {
            for(k=1 ; k<=3 ; k++) 
                if(j-k >= 0 && d[i-1][j-k] != 0)
                    d[i][j] = (d[i][j] + d[i-1][j-k]) % MOD;
        }
                


    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &x, &y);
        sum = 0;
        for(i=1 ; i<=y ; i++) sum = (sum+d[i][x])%MOD;
        printf("%d\n", sum);
    }
}