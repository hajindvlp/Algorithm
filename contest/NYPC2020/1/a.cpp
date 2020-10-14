#include <stdio.h>

char c[100005];
int main() {
    int n, loc = 0;

    scanf("%s", &c[1]);
    n = 1;
    while (c[n]) {
        if (c[n] == 'S') loc++;
        else {
            if (loc % 4 == 0) loc += 4;
            else loc = (loc / 4 + 1) * 4;
        }
        n++;
    }

    printf("%d", loc);
}