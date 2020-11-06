#include <stdio.h>
#include <algorithm>
using namespace std;

int n, check[1001], cnt;
pair<int, int> a[1001][4];

int main()
{
    int i, j, k;
    int tmp[7];

    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=6 ; j++)
            scanf("%d", &tmp[j]);
        for(j=1 ; j<=3 ; j++)
            a[i][j] = make_pair(tmp[j], tmp[j+3]);
        sort(a[i]+1, a[i]+4);
    }

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=3 ; j++)
            printf("%d %d ", a[i][j].first, a[i][j].second);
        printf("\n");
    }

    for(i=1 ; i<=n-1 ; i++)
    {
        if(check[i] == 0)
            for(j=i+1 ; j<=n ; j++)
            {
                for(k=1 ; k<=3 ; k++)
                    if(!(a[i][k].first == a[j][k].first && a[i][k].second == a[j][k].second))
                        break;
                if(k == 4)
                    check[j] = 1, cnt++, printf("%d ", i);
            }
    }
    printf("%d", cnt);
    return 0;
}
