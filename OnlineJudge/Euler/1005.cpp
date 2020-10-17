#include <iostream>
using namespace std;

int main() {
  int N, i, sum = 0;

  cin >> N;
  for(i=1 ; i<=100 ; i++) sum += i*N;
  cout << sum;
}