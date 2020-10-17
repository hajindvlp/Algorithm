#include <iostream>
using namespace std;

int main() {
  int N;

  cin >> N;
  cout << N/2 * (N/2+1) << "\n";
  cout << N*(N+1)/2 - N/2 * (N/2+1) << "\n";
}