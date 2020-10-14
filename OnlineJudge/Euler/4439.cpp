#include <iostream>
#include <string>
using namespace std;

int N;
int lastFish, fishComCnt, baitH, baitN;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  string s;
  int i;

  cin >> N;
  for(i=1 ; i<=N ; i++) {
    cin >> s;
    if(s[0] == 'b') {
      baitH++;
      if(baitH%2 == 0 && baitN < 3) baitN++; 
    }

    if(s[0] == 'f') {
      
    }
  }
}