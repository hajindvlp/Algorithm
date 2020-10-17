#include <iostream>
using namespace std;

int main() {
  int N, i, sum = 0;
  cin >> N;
  for(i=1 ; i<=N ; i++) sum += i*(N-i+1);
  cout << sum;
}