#include <stdio.h>
#include <algorithm>
using namespace std;

int a[4], b[2];

int main() {
    int i;
    
    for(i=0 ; i<4 ; i++) scanf("%d", &a[i]);
    for(i=0 ; i<2 ; i++) scanf("%d", &b[i]);
    sort(a, a+4);
    sort(b, b+2);

    printf("%d", a[1]+a[2]+a[3]+b[1]);
}