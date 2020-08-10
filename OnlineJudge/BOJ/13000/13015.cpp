#include <stdio.h>

int main() {
    int a;
    int i, j;

    scanf("%d", &a);
    for(i=1 ; i<=a ; i++) printf("*");
    for(i=1 ; i<=2*(a-2)+1 ; i++) printf(" ");
    for(i=1 ; i<=a ; i++) printf("*");
    printf("\n");
    for(i=1 ; i<=a-2 ; i++) {
        for(j=1 ; j<=i ; j++) printf(" ");

        printf("*");
        for(j=1 ; j<=a-2 ; j++) printf(" ");
        printf("*");
        
        for(j=1 ; j<=2*(a-i-2)+1 ; j++) printf(" ");

        printf("*");
        for(j=1 ; j<=a-2 ; j++) printf(" ");
        printf("*");

        printf("\n");        
    }
    for(i=1 ; i<=a-1 ; i++) printf(" ");
    printf("*");
    for(i=1 ; i<=a-2 ; i++) printf(" ");
    printf("*");
    for(i=1 ; i<=a-2 ; i++) printf(" ");
    printf("*\n");
    for(i=a-2 ; i>=1 ; i--) {
        for(j=1 ; j<=i ; j++) printf(" ");

        printf("*");
        for(j=1 ; j<=a-2 ; j++) printf(" ");
        printf("*");
        
        for(j=1 ; j<=2*(a-i-2)+1 ; j++) printf(" ");

        printf("*");
        for(j=1 ; j<=a-2 ; j++) printf(" ");
        printf("*");

        printf("\n");        
    }
    for(i=1 ; i<=a ; i++) printf("*");
    for(i=1 ; i<=2*(a-2)+1 ; i++) printf(" ");
    for(i=1 ; i<=a ; i++) printf("*");
}