#include <stdio.h>

unsigned long long int d[31][80];

unsigned long long int rec(int w, int h) {
    // printf("%d %d\n", w, h);
    if(d[w][h]) return d[w][h];
    else {
        if(w>0) d[w][h] += rec(w-1, h+1);
        if(h>0) d[w][h] += rec(w, h-1);
        return d[w][h];
    }
}


int main() {
    int x;
    int i, j;

    d[0][0] = 1;
    rec(30, 0);

    while(1) {
        scanf("%d", &x);
        if(x == 0) break;
        printf("%llu\n", d[x][0]);
    }
}