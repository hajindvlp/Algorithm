#include <stdio.h>
#include <algorithm>
#define N 10
using namespace std;

struct p{
    double x1, y1, x2, y2;
} a[N+1];

double x[2*N+1], y[2*N+1], sum;
bool check[2*N+1][2*N+1];
int n;

int get_index(double val, double * arr)
{
    int i;

    for(i=1 ; i<=2*n ; i++)
        if(arr[i] == val)
            return i;
}

int main()
{
    int i, j, k;
    int x1, x2, y1, y2;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        scanf("%lf %lf %lf %lf", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
        x[2*(i-1)+1] = a[i].x1, x[2*(i-1)+2] = a[i].x2;
        y[2*(i-1)+1] = a[i].y1, y[2*(i-1)+2] = a[i].y2;
    }
    sort(x+1, x+2*n+1);
    sort(y+1, y+2*n+1);

    for(i=1 ; i<=n ; i++)
    {
        x1 = get_index(a[i].x1, x);
        y1 = get_index(a[i].y1, y);
        x2 = get_index(a[i].x2, x);
        y2 = get_index(a[i].y2, y);
        for(j=y1 ; j<y2 ; j++)
            for(k=x1 ; k<x2 ; k++)
                if(!check[j][k])
                {
                    check[j][k] = true;
                    sum+=(y[j+1]-y[j])*(x[k+1]-x[k]);
                }
    }

    printf("%.2lf", sum);
}
