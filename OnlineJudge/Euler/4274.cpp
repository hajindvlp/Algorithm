#include <iostream>
using namespace std;

int N, L;

int main() {
  int i = 0, cnt = 0;
  cin >> N >> L;
  while(cnt < N) {
    i++;
    int tmp = i;
    bool flag = false;
    while(tmp) {
      if(tmp%10 == L) flag = true;
      tmp /= 10;
    }
    if(!flag) cnt++;
  }
  cout << i;
}