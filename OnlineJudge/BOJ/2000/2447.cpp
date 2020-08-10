#include <stdio.h>
#include <math.h>

int d[6565][6565];

void rec(int y, int x, int s) {
    if(s == 0) d[y][x] = 1;
    else {
        int l = (int)pow(3, s-1);
        rec(y, x, s-1);
        rec(y, x+l, s-1);
        rec(y, x+2*l, s-1);
        rec(y+l, x, s-1);
        rec(y+l, x+2*l, s-1);
        rec(y+2*l, x, s-1);
        rec(y+2*l, x+l, s-1);
        rec(y+2*l, x+2*l, s-1);
    }
}

int main() {
    int a, x = 1, i, j;
    int n = 0;

    scanf("%d", &a);
    while(x != a) x*=3, n++;
    rec(1, 1, n);

    for(i=1 ; i<=a ; i++) {
        for(j=1 ; j<=a ; j++) {
            if(d[i][j]) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}