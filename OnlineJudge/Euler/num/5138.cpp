#include <stdio.h>

int n, p[10001], e[10001];

void init()
{
    int i;

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        p[i] = i;
}

int getFp(int x)
{
    while(x != p[x])
        x = p[x];

    return x;
}

int getEp(int x)
{
    while(x != e[x])
        x = e[x];

    return x;
}

int setF(int x, int y)
{
    int px, ex, py, ey;

    px = getFp(x);
    ex = getEp(x);
    py = getFp(y);
    ey = getEp(y);


}

int setE(int x, int y)
{

}

int areF(int x, int y)
{

}

int areE(int x, int y)
{

}
