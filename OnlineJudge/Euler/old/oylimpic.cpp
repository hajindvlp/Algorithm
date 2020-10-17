#include <stdio.h>

int n, m, a[1001][5], cnt = 1;

int main()
{
    int i, j;

    scanf("%d %d", &n, &m);
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=4 ; j++)
            scanf("%d", &a[i][j]);

    for(i=1 ; i<=n ; i++)
        if(a[i][1] == m)
        {
            m = i;
            break;
        }

    for(i=1 ; i<=n ; i++)
        if(i != m)
        {
            if(a[i][2]>a[m][2])
                cnt++;
            else if(a[i][2] == a[m][2] && a[i][3]>a[m][3])
                cnt++;
            else if(a[i][2] == a[m][2] && a[i][3] == a[m][3] && a[i][4]>a[m][4])
                cnt++;
        }

    printf("%d", cnt);
    return 0;
}
