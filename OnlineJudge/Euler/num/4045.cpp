#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define DX 10

void fact2(int n)
{
    int i, j, r, cnt;

    vector<char> vc;
    vector<char>::iterator it;

    vc.push_back(1);

    for(i = 2; i <= n; i++)
    {
        j = 0;
        while(!vc[j]) j++;

        for(r = 0; j < vc.size(); j++)
        {
            r += vc[j] * i;
            vc[j] = r % DX;
            r /= DX;
        }
        while(r)
        {
            vc.push_back(r % DX);
            r /= DX;
        }
    }

    cnt = vc.size();
    int N = 0;
    for (i = cnt - 1; i >= 0; i--)
    {
        printf("%d",vc[i]);
        if(++N > 100) break;
    }
}



int main()
{
    int n;

    scanf("%d", &n);
    fact2(n);
}
