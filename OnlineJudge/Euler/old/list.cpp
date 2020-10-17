#include <stdio.h>
#include <algorithm>
using namespace std;


int cnt[101], a[101];

int main()
{
    int x = -1, i = 0, j;

    while(1)
    {
        scanf("%d", &x);
        if(x == 0)
            break;
        if(cnt[x] != 0)
        {
            for(j=1 ; j<=i ; j++)
                if(a[j] == x)
                    a[j] = 500;
        }
        else if(x!=0)
        {
            i++;
            a[i] = x;
            cnt[x] = i;
        }
        sort(a+1, a+i+1);
        for(j=1 ; j<=i ; j++)
        {
            if(a[j] == 500)
                break;
            else
                printf("%d ", a[j]);
        }
    }
    return 0;
}
