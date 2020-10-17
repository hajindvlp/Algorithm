#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string str_romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
char base_romans[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
vector<int> cnt(26, 0);
vector<pair<int, int> > ans;

vector<int> int2rom(int n) {
  vector<int> a(26, 0);
  int i, values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  for (i = 0; i < 13; i++) 
    while(n - values[i] >= 0) {
      n -= values[i];
      if(i%2 == 1) a[str_romans[i][0]-'A']++, a[str_romans[i][1]-'A']++; 
      else a[str_romans[i][0]-'A']++;
    }
  return a;
}

int main() {
  int i, j, N;

  cin >> N;
  for(i=1 ; i<=N ; i++) {
    vector<int> tt = int2rom(i);
    for(j=0 ; j<26 ; j++) cnt[j] += tt[j];
  }

  for(i=0 ; i<7 ; i++) 
    if(cnt[base_romans[i]-'A'] != 0)
      cout << base_romans[i] << " " << cnt[base_romans[i]-'A'] << "\n";
}