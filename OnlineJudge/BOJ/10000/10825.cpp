#include <bits/stdc++.h>
using namespace std;
 
struct X{
    string s;
    int a, b, c;
    X(int x = 0, int y = 0, int z = 0):a(x), b(y), c(z){}
};
 
int main()
{
    int n;
    cin >> n;
    vector<X> v(n);
    for(auto &x : v) cin >> x.s >> x.a >> x.b >> x.c;
     
    sort(v.begin(), v.end(), [](const X& x, const X& y) -> bool{
        if(x.a != y.a) return x.a > y.a;
        if(x.b != y.b) return x.b < y.b;
        if(x.c != y.c) return x.c > y.c;
        return x.s < y.s;
    });
 
    for(auto &x : v) cout << x.s << endl;
}