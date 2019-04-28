#include <stdio.h>
#include <algorithm>
using namespace std;

struct point{
    int x1, x2, y1, y2;
} a[501];

int n, x[1001], y[1001], sum;
bool check[1001][1001];

int get_index(int x, int *arr)
{
    int i;

    for(i=1 ; i<=n*2 ; i++)
        if(x == arr[i])
            return i;
}

int main()
{
    int i, j, k;
    int x1, x2, y1, y2, w, h;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d %d %d", &a[i].x1, &a[i].y1, &w, &h);
        a[i].x2 = a[i].x1+w;
        a[i].y2 = a[i].y1+h;
        x[(i-1)*2+1] = a[i].x1, x[i*2] = a[i].x2;
        y[(i-1)*2+1] = a[i].y1, y[i*2] = a[i].y2;
    }

    sort(x+1, x+2*n+1);
    sort(y+1, y+2*n+1);

    for(i=1 ; i<=n ; i++)
    {
        x1 = get_index(a[i].x1, x);
        x2 = get_index(a[i].x2, x);
        y1 = get_index(a[i].y1, y);
        y2 = get_index(a[i].y2, y);
        for(j=y1 ; j<y2 ; j++)
            for(k=x1 ; k<x2 ; k++)
                if(!check[j][k])
                {
                    check[j][k] = true;
                    sum+=(y[j+1]-y[j])*(x[k+1]-x[k]);
                }
    }
    printf("%d", sum);
    return 0;
}
