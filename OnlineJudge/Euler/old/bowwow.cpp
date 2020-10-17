#include <stdio.h>

int a, b, c, d;
int x[4];
int ans[4];

int main()
{
    int i;
    scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &x[1], &x[2], &x[3]);
    for(i=1 ; i<=3 ; i++)
    {
        if(x[i]%(a+b)>0 && x[i]%(a+b)<=a)
            ans[i]++;
        if(x[i]%(c+d)>0 && x[i]%(c+d)<=c)
            ans[i]++;
    }
    for(i=1 ; i<=3 ; i++)
    {
        if(ans[i] == 1)
            printf("one\n");
        else if(ans[i] == 2)
            printf("both\n");
        else
            printf("none\n");
    }
}
