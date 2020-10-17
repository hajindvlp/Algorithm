#include <stdio.h>
#include <string.h>

int n, m;
char d[101][1001];

void pl(int x, int y, int z)
{
    int i, ylen, zlen, alen;
    char tmp[1001];

    ylen = strlen(d[y]);
    zlen = strlen(d[z]);
    if(ylen>zlen)
    {
        for(i=0 ; i<ylen ; i++)
        {
            if(i>ylen-zlen)
                tmp[i] += (d[y][i]-'0'+d[z][i-(ylen-zlen)-1]-'0')%10, tmp[i+1] += (d[y][i]-'0'+d[z][i-(ylen-zlen)-1]-'0')/10;
            else
                tmp[i] += (d[y][i]-'0')%10, tmp[i+1] += (d[y][i]-'0')/10;
        }
    }
    else
    {
        for(i=0 ; i<zlen ; i++)
        {
            if(i<ylen)
                tmp[i] += (d[y][i]-'0'+d[z][i]-'0')%10, tmp[i+1] += (d[y][i]-'0'+d[z][i]-'0')/10;
            else
                tmp[i] += (d[z][i]-'0')%10, tmp[i+1] += (d[z][i]-'0')/10;
        }
    }

    alen = strlen(tmp);
    for(i=0 ; i<alen ; i++)
        d[x][i] = tmp[i]+'0';
}

int main()
{
    int i, j;

    scanf("%d %d", &n, &m);

    scanf("%s", &d[1][0]);
    scanf("%s", &d[2][0]);
    pl(3, 1, 2);
    printf("%s", d[3]);

    /*d[0][0] = 1;
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=m ; j++)
            if(i-j>=0)
                pl(i, i-j, i);
    printf("%llu", d[n]);*/
    return 0;
}
