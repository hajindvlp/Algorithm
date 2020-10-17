#include <stdio.h>
#include <queue>
#define INF 1000000000
using namespace std;

queue<int> Q;
int n, m, d[100001];

int main()
{
    int x, i;

    scanf("%d %d", &n, &m);

    for(i=1 ; i<=100000 ; i++)
        d[i] = INF;

    Q.push(n);
    d[n] = 0;
    while(!Q.empty())
    {
        x = Q.front(), Q.pop();
        if(x+1>0 && x+1<=100000 && d[x+1]>d[x]+1)
            d[x+1] = d[x]+1, Q.push(x+1);
        if(x-1>0 && x-1<=100000 && d[x-1]>d[x]+1)
            d[x-1] = d[x]+1, Q.push(x-1);
        if(x*2>0 && x*2<=100000 && d[x*2]>d[x]+1)
            d[x*2] = d[x]+1, Q.push(x*2);
    }

    printf("%d", d[m]);
    return 0;
}
