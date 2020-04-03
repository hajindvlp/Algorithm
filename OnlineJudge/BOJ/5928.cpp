#include <stdio.h>

int main() {
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    a-=11;
    b-=11;
    c-=11;

    if(c<0) {
        c = (c+60) %60;
        b--;
    } if(b<0) {
        b = (b+60)%60;
        a--;
    }

    if(a<0) printf("-1");
    else printf("%d", a*24*60+b*60+c);
}