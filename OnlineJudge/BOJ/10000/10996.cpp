#include <stdio.h>

int main() {
    int a, i, j;

    scanf("%d", &a);
    for(i=1 ; i<=a ; i++) {
        int size = a/2;
        if(a%2) size++;;
        for(j=1 ; j<=size ; j++) printf("* ");
        printf("\n");
        for(j=1 ; j<=a-size ; j++) printf(" *");
        printf("\n");
    }
}