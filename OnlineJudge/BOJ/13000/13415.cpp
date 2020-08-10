#include <stdio.h>
#include <algorithm>
using namespace std;

int a[100001];
int n, k, x, y;

bool desc(int a, int b){
    return a > b;
}

int main()
{
    int i, j;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);

    scanf("%d", &k);
    for(i=1 ; i<=k ; i++)
    {
        scanf("%d %d", &x, &y);
        sort(a+1, a+x+1);
        sort(a+1, a+y+1, desc);
    }

    for(i=1 ; i<=n ; i++)
        printf("%d ", a[i]);
}
