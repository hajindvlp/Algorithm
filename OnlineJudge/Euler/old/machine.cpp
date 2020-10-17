#include <stdio.h>

int n, m;
int a[11], cnt;

int main()
{
    int i;
    int tmp;

    scanf("%d %d", &m, &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);

    do{
        tmp = 0;
        cnt++;
        for(i=1 ; i<=n ; i++)
            tmp += cnt/a[i];
    }while(tmp < m);

    printf("%d", cnt);
}
