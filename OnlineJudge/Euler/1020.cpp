#include <iostream>
using namespace std;

int ecnt, ocnt, N;

int main() {
  int i;
  cin>>N;
  while(N--) cin >> i, i%2?ocnt+=i:ecnt+=i;
  cout << ecnt << " " << ocnt << "\n";
}