#include <stdio.h>
#include <vector>
using namespace std;

vector<int> v;
int n, cnt = 1, zcnt;
int d[5000001];

int main()
{
    int mod = 7, i;

    scanf("%d", &n);

    v.push_back(mod);
    mod = mod%n;
    while(1)
    {
        if(mod == 0)
            break;
        else if(d[(mod*10+7)%n])
            d[(mod*10+7)%n] = 0, mod = (mod*10)%n, v.push_back(0);
        else
            mod = (mod*10+7)%n, v.push_back(7), d[mod] = 1;
    }
    int len = v.size();
    for(i=0 ; i<len ; i++)
        printf("%d", v[i]);
    return 0;
}
