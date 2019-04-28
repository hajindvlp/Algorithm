#include <stdio.h>

void pro(int num)
{
    int n, i;
    char a[10005];

    for(i=1 ; i<=10000 ; i++)
        a[i] = 0;
    scanf("%d", &n);
    scanf("%s", &a[1]);
    printf("Case #%d: ", num);
    for(i=1 ; i<=2*n-2 ; i++)
        printf("%c", (a[i] == 'S')?'E':'S');
    printf("\n");
}

int main()
{
    int i, t;

    scanf("%d", &t);
    for(i=1 ; i<=t ; i++)
        pro(i);
}
