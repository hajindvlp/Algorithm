#include <iostream>
#include <map>
#include <vector>
using namespace std;

void pro() {
  map<long long, int> m;
  vector<long long> v;
  long long a, b, s, e, n, i;
  long long rep, offset, length;
  bool isModable = false;

  cin >> a >> b;
  cin >> s >> n;
  e = s+n-1;

  a = a%b;
  a *= 10;
  offset = 1;
  m[a] = 1;

  while(1) {
    v.push_back(a/b);
    a = a%b;  
    a *= 10;
    if(a == 0) {
      isModable = true;
      length = 1;
      break;
    }
    if(m[a]) {
      length = offset - m[a] + 1;
      break;
    }
    m[a] = ++offset;
  }

  offset -= length;

  if(isModable) {
    if(s <= offset+1) {
      if(offset < e-1) for(i=s-1 ; i<offset ; i++) cout << v[i];
      else for(i=s-1 ; i<e-1 ; i++) cout << v[i];
      for(i=s-1; i<(offset<e-1)?offset:e-1; i++) cout << v[i];
    }
    if(e > offset+1) for(i=1;i<=e-offset-1 ; i++) cout << 0;
  } else {

  }

  cout << "\n";
  int size = v.size();
  for(i=0 ; i<size ; i++) cout << v[i];
  cout << "\n" << offset << " " << length;
}

int main() {
  // cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) pro();
}