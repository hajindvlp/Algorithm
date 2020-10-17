#include <iostream>
using namespace std;

int main() {
  int N, i, sum = 1;
  cin >> N;
  cout << N << "!=(1";
  for(i=2 ; i<=N ; i++) {
    cout << "*" << i;
    sum *= i;
  }
  cout << ")=" <<  sum;
}