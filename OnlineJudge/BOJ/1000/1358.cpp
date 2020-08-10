#include <stdio.h>
#include <math.h>

int x, y, w, h, r;
int n, cnt;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

int main() {
    int x1, y1;

    scanf("%d %d %d %d %d", &w, &h, &x, &y, &n);
    while(n--) {
        scanf("%d %d", &x1, &y1);
        if(x<=x1 && x1<=x+w && y<=y1 && y1<=y+h) cnt++;
        else if(x1<x && dist((double)x1, (double)y1, (double)x, (double)y+h/2) <= double(h/2)) cnt++;
        else if(x+w<x1 && dist((double)x1, (double)y1, (double)x+w, (double)y+h/2) <= double(h/2)) cnt++;
    }

    printf("%d", cnt);
}