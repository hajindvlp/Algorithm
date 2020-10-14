#include <iostream>
#include <string>
using namespace std;

int tree[260], N, M;

int sti(string s) {
  int i, len = s.length();
  int res = 1;
  for(i=0 ; i<len ; i++) {
    if(s[i] == 'L') res = res*2;
    else if(s[i] == 'R') res = res*2+1;
  }

  M = max(res, M);

  return res;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int i, j, t;
  bool flag = false;
  string s;

  cin >> N;
  for(i=1 ; i<=N ; i++) {
    if(flag) {
      flag = false;
      cin >> s;
      tree[sti(s)] = t;
    } else {
      cin >> t >> s;
      if(s[0]!='L' && s[0]!='R') {
        tree[1] = t;
        t = stoi(s);
        flag = true;
      } else {
        tree[sti(s)] = t;
      }
    }
  }

  for(i=1 ; i<=M ; i++) 
    if(tree[i] != 0) cout << tree[i] << " ";
}