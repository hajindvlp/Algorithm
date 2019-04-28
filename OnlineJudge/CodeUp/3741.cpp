#include<iostream>
#include<cmath>

int fib(int n) {
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));
}

// Driver Code
int main ()
{
  int n = 9;
  std::cout << fib(n-1) << std::endl;
  return 0;
} 
