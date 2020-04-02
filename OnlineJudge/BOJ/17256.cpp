#include <stdio.h>

int main() {
    int a1, a2, a3;
    int b1, b2, b3;

    scanf("%d %d %d %d %d %d", &a1, &a2, &a3, &b1, &b2, &b3);
    printf("%d %d %d", b1-a3, b2/a2, b3-a1);
}