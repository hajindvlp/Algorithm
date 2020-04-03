#include <stdio.h>
#include <string>
#include <iostream>
#include <regex>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        cin >> s;
        regex p("(100+1+|01)+");
        cout << (regex_match(s, p) ? "YES" : "NO") << endl;
    }
}