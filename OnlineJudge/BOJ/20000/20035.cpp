#include <iostream>
#include <algorithm>
#define INF 10000000
#define MAX 100001
using namespace std;

int n, a[MAX], d[MAX], cnt, mx;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i, k;

    cin >> n;
    for(i=1 ; i<=n ; i++)
        d[i] = INF;

    for(i=1 ; i<=n ; i++)
    {   
        cin >> a[i];
        k = lower_bound(d+1, d+cnt+1, a[i])-d;
        cnt++;
        if(k>mx)
            mx = k;
        d[k] = a[i];
    }
    cout << n-mx;
}