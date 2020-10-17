#include <iostream>
using namespace std;

int main() {
  int N, i, sum = 0;
  cin >> N;
  for(i=1 ; i<=N ; i++) sum += (i%2==0)?-i*i:i*i;

  cout << sum;
}