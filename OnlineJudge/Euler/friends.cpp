#include <stdio.h>

int n, m;
int p[200001], a[20001];

int find(int x)
{
    while(p[x] != x)
        x = p[x];
    return x;
}

void merge(int x, int y)
{
    int 
}

int main()
{
    int i;
    int x, y, z;

    scanf("%d %d", &n, &m);

    for(i=2 ; i<=n ; i++)
    {
        scanf("%d", &x);
        p[i] = parent(x);
    }

    for(i=1 ; i<=m+n-1 ; i++)
    {
        scanf("%d", &x);
        if(x == 0)
        {
            scanf("%d", &y);
            p[y] = y;
        }
        else
        {
            scanf("%d %d", &y, &z);
            if(parent(p[y]) == parent(p[z]))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
