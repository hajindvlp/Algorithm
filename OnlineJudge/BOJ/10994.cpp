#include <stdio.h>

int a[405][405];
int main() {
    int n, i, j, k;
    int x, y;

    scanf("%d", &n);
    x = y = 2*n-1;
    for(k=1 ; k<=n ; k++) {
        for(i=y-2*(k-1) ; i<=y+2*(k-1) ; i++) {
            for(j=x-2*(k-1) ; j<=x+2*(k-1) ; j++)
                if(i==y-2*(k-1)||i==y+2*(k-1)||j==x-2*(k-1)||j==x+2*(k-1))
                    a[i][j] = 1;
        }
    }

    for(i=1 ; i<=4*(n-1)+1 ; i++) {
        for(j=1 ; j<=4*(n-1)+1 ; j++) {
            if(a[i][j]) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}