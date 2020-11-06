#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int N;
string S, t;
unordered_map<string, bool> visit;
bool v[205];

void rec(int lev) {
  if(lev == N && !visit[t]) {
    visit[t] = true;
    cout << t << "\n"; 
  } else {
    for(int i=0 ; i<N ; i++) 
      if(!v[i]) {
        v[i] = true;
        t.push_back(S[i]);
        rec(lev+1);
        t.pop_back();
        v[i] = false;
      }
  }
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin>>S;
  N = S.size();
  sort(S.begin(), S.end());
  rec(0);
}