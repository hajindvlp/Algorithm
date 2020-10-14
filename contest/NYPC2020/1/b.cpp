#include <stdio.h>
#include <algorithm>
using namespace std;

typedef pair<pair<int, int>, int> piii;

piii t1, t2, t3, t;

int main() {
    int x, y, z;
    int n, i;

    scanf("%d:%d:%d", &x, &y, &z), t1 = { {x, y}, z };
    scanf("%d:%d:%d", &x, &y, &z), t2 = { {x, y}, z };
    scanf("%d:%d:%d", &x, &y, &z), t3 = { {x, y}, z };
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d:%d:%d", &x, &y, &z), t = { {x, y}, z };
        if (t <= t3) printf("***\n");
        else if (t <= t2) printf("**\n");
        else if (t <= t1) printf("*\n");
        else printf(":(\n");
    }
}