#include <stdio.h>

int a[101][101], n;

int main() {
    int i, j, k;

    scanf("%d", &n);    
    for(i=1 ; i<=n ; i++) for(j=1 ; j<=n ; j++) scanf("%d", &a[i][j]);
    for(k=1 ; k<=n ; k++) for(i=1 ; i<=n ; i++) for(j=1 ; j<=n ; j++)
        if(a[i][k] && a[k][j]) a[i][j] = 1;

    for(i=1 ; i<=n ; i++) {
        for(j=1 ; j<=n ; j++) printf("%d ", a[i][j]);
        printf("\n");
    }
} 