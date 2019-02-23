#include <stdio.h>
#include <algorithm>
using namespace std;

int a[6][6], p[26];
bool c[6][6];
pair<int, int> w[26];

int isBingo()
{
    int i, j, cnt = 0;
    cnt = 0;

    for(i=1 ; i<=5 ; i++)
    {
        for(j=1 ; j<=5 ; j++)
            if(!c[i][j])
                break;
        if(j==6)
            cnt++;
    }

    for(i=1 ; i<=5 ; i++)
    {
        for(j=1 ; j<=5 ; j++)
            if(!c[j][i])
                break;
        if(j==6)
            cnt++;
    }

    for(i=1 ; i<=5 ; i++)
        if(!c[i][i])
            break;
    if(i==6)
        cnt++;

    for(i=1 ; i<=5 ; i++)
        if(!c[i][6-i])
            break;
    if(i==6)
        cnt++;

    return cnt;
}

int main()
{
    int i, j;

    for(i=1 ; i<=5 ; i++)
        for(j=1 ; j<=5 ; j++)
            scanf("%d", &a[i][j]), w[a[i][j]] = make_pair(i, j);

    for(i=1 ; i<=25 ; i++)
        scanf("%d", &p[i]);

    for(i=1 ; i<=25 ; i++)
    {
        c[w[p[i]].first][w[p[i]].second] = true;
        if(isBingo()>=3)
        {
            printf("%d", i);
            return 0;
        }
    }
}
