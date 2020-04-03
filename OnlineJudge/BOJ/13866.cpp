#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int a[5], i;

    for(i=1 ; i<=4 ; i++) scanf("%d",&a[i]);
    sort(a+1, a+4+1);
    printf("%d", abs(a[4]+a[1]-a[2]-a[3]));
}