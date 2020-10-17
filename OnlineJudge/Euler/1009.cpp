#include <iostream>
using namespace std;

int main() {
  int a, b, i, sum = 0;

  cin >> a >> b;
  for(i=a ; i<=b ; i++) if(i%2) sum += i;
  cout << sum;
}