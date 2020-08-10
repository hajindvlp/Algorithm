#include <stdio.h>

int main() {
    int a;
    int i, j;

    scanf("%d", &a);
    for(i=1 ; i<=a ; i++) {
        for(j=1 ; j<=a-i ; j++) printf(" ");
        printf("*");
        for(j=1 ; j<=2*(i-1)-1 ; j++) printf(" ");
        if(i!=1) printf("*");
        printf("\n");
    }
}