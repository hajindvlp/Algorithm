#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pp;

vector<pp> a;
int n, m;
pp tmp;

bool compare(pp x, pp y)
{
    if(x<y)
        return false;
    return true;
}

int main()
{
    int i, j, len, x;

    scanf("%d %d", &n, &m);

    for(i=1 ; i<=n ; i++)
    {
        scanf("%d", &x);
        len = a.size();
        for(j=0 ; j<len ; j++)
            if(a[j].second == x)
            {
                a[j].first++;
                break;
            }
        if(j == len)
            a.push_back(make_pair(1, x));
    }

    len = a.size();
    for(i=0 ; i<len ; i++)
        for(j=0 ; j<i ; j++)
            if(a[i].first>a[j].first)
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }

    for(i=0 ; i<len ; i++)
        for(j=1 ; j<=a[i].first ; j++)
            printf("%d ", a[i].second);
    return 0;
}
