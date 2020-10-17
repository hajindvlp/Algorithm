#include <stdio.h>

int dur[16], f[16], n, t;
int form[16], path[16], d[16];

int main()
{
    int i, j;

    scanf("%d %d", &n, &t);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &dur[i]);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &f[i]);

    for(i=1 ; i<=n ; i++)
    {
        if(d[dur[i]]<f[i])
            tmp[dur[i]] = f[i], ;
        for(j=1 ; j<=t ; j++)
            if(d[j]!=0 && d[j+dur[i]]<d[j]+f[i])
                tmp[j+dur[i]] = d[j]+f[i];
    }
}
