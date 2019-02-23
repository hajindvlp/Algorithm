#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> a;

int main()
{
    int i;

    scanf("%d %d", &n, &m);
    n+=m;

    for(i=1 ; i<=n ; i++)
        scanf("%d", &m), a.push_back(m);

    sort(a.begin(), a.end());
    for(i=0 ; i<n ; i++)
        printf("%d ", a[i]);
    return 0;
}
