#include <iostream>
#include <string>
using namespace std;

void pro() {
  int N, i, cnt;
  string s;
  cin >> N >> s;
  cnt = N;
  for(i=0 ; i<N ; i++) 
    if((s[i%N] == '<' && s[(i+1)%N] == '>') || 
       (s[i%N] == '>' && s[(i+1)%N] == '<')) cnt--;
  cout << cnt << "\n";
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) pro();
}