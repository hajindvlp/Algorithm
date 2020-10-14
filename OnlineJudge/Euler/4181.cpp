#include <iostream>
#include <bitset>
#include <string>
#include <queue>
#include <map>
using namespace std;

queue<bitset<20> > Q;
map<bitset<20>, int> D;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  string s;
  int i;

  cin >> s;
  bitset<20> B(s);

  Q.push(B);
  while(!Q.empty()) {
    bitset<20> yy = Q.front();
    bitset<20> tt = yy;
    Q.pop();
    for(i=1 ; i<=20 ; i++) {
      if(i-1>0) tt.flip(i-1);
      tt.flip(i);
      if(i+1<=20) tt.flip(i+1);
      
      if(D[tt] == 0 || D[tt] > D[yy]+1) {
        D[tt] = D[yy]+1;
        Q.push(tt);
      }

      if(i-1>0) tt.flip(i-1);
      tt.flip(i);
      if(i+1<=20) tt.flip(i+1);
    }
  }

  bitset<20> target;
  target.reset();
  cout << D[target] << "\n";
}