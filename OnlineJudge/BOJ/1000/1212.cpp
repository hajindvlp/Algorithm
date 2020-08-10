#include <iostream>
#include <string>
using namespace std;

int main() {
    string oct;
    string iN[8] = {"0", "1", "10", "11", "100", "101", "110", "111"};
    string N[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};

    cin >> oct;

    int len = oct.length();
    cout << iN[oct[0]-'0'];
    for(int i=1 ; i<len ; i++) cout << N[oct[i]-'0'];
    cout << endl;
}