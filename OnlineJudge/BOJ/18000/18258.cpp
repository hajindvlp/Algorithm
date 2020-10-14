#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> Q;

int main() {
  int n, x;
  string cmd;

  cin >> n;
  while(n--) {
    cin >> cmd;

    if(cmd == "push") scanf("%d", &x), Q.push(x);
    else if(cmd == "pop") {
      cout << Q.empty() ? -1 : Q.front();
      if(!Q.empty()) Q.pop();
    }
    else if(cmd == "size") cout << Q.size();
    else if(cmd == "empty") cout <<  Q.empty();
    else if(cmd == "front") cout <<  Q.empty() ? -1 : Q.front();
    else cout << Q.empty() ? -1 : Q.back();
  }
}