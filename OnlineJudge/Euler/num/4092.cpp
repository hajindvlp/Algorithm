#include <stdio.h>
#include <string.h>

char c[8][6] = {"000000",
                "001111",
                "010011",
                "011100",
                "100110",
                "101001",
                "110101",
                "111010"};
char a[10][6];
int n;

int main()
{
    int i, j;

    scanf("%d ", &n);
    for(i=1 ; i<=n ; i++)
    {
        for(j=0 ; j<6 ; j++)
            scanf("%c", &a[i][j]);
    }

    
}
