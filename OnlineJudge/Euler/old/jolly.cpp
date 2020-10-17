#include <stdio.h>

int c[3001], n, a[3001];

int abs(int x)
{
    if(x<0)
        return -x;
    return x;
}

void pro()
{
    int i;
    int x, y;

    scanf("%d", &n);

    for(i=1 ; i<=n ; i++)
        c[i] = 0;

    for(i=1 ; i<=n ; i++)
        scanf("%d", &a[i]);

    for(i=1 ; i<=n-1 ; i++)
    {
        if(abs(a[i]-a[i+1])>=3000 || a[i] == a[i+1])
        {
            printf("Not Jolly\n");
            return;
        }
        else
            c[abs(a[i]-a[i+1])] = 1;
    }

    for(i=1 ; i<=n-1 ; i++)
        if(!c[i])
        {
            printf("Not Jolly\n");
            return;
        }
    printf("Jolly\n");

    return;
}

int main()
{
    pro();
    pro();
    return 0;
}
