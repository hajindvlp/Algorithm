#include <stdio.h>
#include <math.h>

int n;
int a[11];
double m;

int main()
{
    int i;

    scanf("%d %d", &m, &n);
    int tmp = m;
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]), m = (double)(1+a[i]/100)*m;

    printf("%d", m-tmp);
    return 0;
}
