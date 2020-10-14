#include <iostream>
#include <map>
using namespace std;

map<int, int> M;
int N, cnt, ss, ans;

int mNum(int x) {
  return (x/10)%10000;
}

int rNum(int x) {
  return x % 1000000;
}

int main() {
  int i;

  cin >> N;
  while(1) {
    i++;
    int midNum = mNum(N);
    int midNumS = midNum*midNum;
    int res = rNum(midNumS);
    if(M[res] != 0) {
      cnt = i-M[res];
      ss = i;
      ans = res;
      break;
    }
    M[res] = i;
    N = res;
  }

  cout << ans << " " << cnt << " " << ss;
}