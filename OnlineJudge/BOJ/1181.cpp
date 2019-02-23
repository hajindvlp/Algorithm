#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

pair<int, string> a[20001];
int n;

int main()
{
    int i;

    cin >> n;
    for(i=1 ; i<=n ; i++)
        cin >> a[i].second, a[i].first = a[i].second.size();

    sort(a+1, a+n+1);
    for(i=1 ; i<=n ; i++)
        if(a[i-1]!=a[i])
            cout << a[i].second << endl;
    return 0;
}
