#include <iostream>
#include <math.h>
using namespace std;

double p, q, r;
double a, b, c;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> p >> q >> r;
  a = (p+q-r)/2;
  b = (p-q+r)/2;
  c = (-p+q+r)/2;
  
  if(a > 0 && b > 0 && c > 0) {
    printf("1\n%.1f %.1f %.1f", round(a*10)/10, round(b*10)/10, round(c*10)/10);
  } else {
    cout << "-1\n";
  } 
}