#include <stdio.h>
#include <string.h>

char c[105];

int main()
{
    int i, len;

    gets(&c[1]);
    len = strlen(&c[1]);

    for(i=1 ; i<=len ; i++)
    {
        if(c[i] == ',')
            printf(" ");
        else if(c[i] == ' ')
            continue;
        else if(c[i] == ';')
            printf("\n");
        else
            printf("%c", c[i]);
    }
}
