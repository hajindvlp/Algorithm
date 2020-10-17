#include <iostream>
using namespace std;

int main() {
  int N, i, sum = 0;
  cin >> N;
  for(i=1 ; i<N ; i++) if(i%3==0||i%5==0) sum += i;
  cout << sum;
}