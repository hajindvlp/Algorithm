#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
pair<int, string>  a[100001];

int main()
{
    int i;

    cin >> n;
    for(i=1 ; i<=n ; i++)   
        cin >> a[i].first >> a[i].second;
    
    sort(a+1, a+n+1);
    for(i=1 ; i<=n ; i++)
        cout << a[i].first << " " << a[i].second << endl;

    return 0;
}