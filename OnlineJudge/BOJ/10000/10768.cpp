#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    pair<int, int> x, y;
    int t1, t2;

    scanf("%d %d", &t1, &t2);
    x = {2, 18};
    y = {t1, t2};
    if(x>y) printf("Before");
    else if(x==y) printf("Special");
    else printf("After");
}