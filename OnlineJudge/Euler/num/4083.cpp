#include <stdio.h>
#include <string.h>

char a[1001], b[1001];
int d[1001][1001];

int main()
{
    int aln, bln, i, j, k = 0;

    scanf("%s", &a[1]);
    scanf("%s", &b[1]);
    aln = strlen(&a[1]);
    bln = strlen(&b[1]);

    for(i=1 ; i<=aln ; i++)
        for(j=1 ; j<=bln ; j++)
        {
            if(a[i] == b[j])
                d[i][j] = d[i-1][j-1]+1;
            else
            {
                if(d[i-1][j] > d[i][j-1])
                    d[i][j] = d[i-1][j];
                else
                    d[i][j] = d[i][j-1];
            }
        }
    printf("%d", d[aln][bln]);
    return 0;
}
