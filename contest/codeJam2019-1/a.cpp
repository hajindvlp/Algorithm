#include <stdio.h>
#include <string.h>

int a[10][2]={{0, 0}, {1, 0}, {1, 1}, {2, 1}, {3, 1}, {3, 2}, {5, 1}, {6, 1}, {7, 1}, {8, 1}};
char s[101];
int ans1[101], ans2[101];

void pro(int num)
{
    int i, n;

    for(i=1 ; i<=100 ; i++)
        s[i] = ans1[i] = ans2[i] = 0;

    scanf("%s", &s[1]);
    n = strlen(&s[1]);

    for(i=1 ; i<=n ; i++)
        ans1[i] = a[s[i]-'0'][0], ans2[i] = a[s[i]-'0'][1];

    printf("Case #%d: ", num);
    for(i=1 ; i<=n ; i++)
        if(!(i == 1 && ans1[i]==0))
            printf("%d", ans1[i]);
    printf(" ");
    for(i=1 ; i<=n ; i++)
        if(!(i == 1 && ans2[i]==0))
            printf("%d", ans2[i]);
    printf("\n");
}

int main()
{
    int t, i;

    scanf("%d", &t);
    for(i=1 ; i<=t ; i++)
        pro(i);
}
