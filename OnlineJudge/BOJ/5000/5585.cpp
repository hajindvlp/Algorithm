#include <iostream>
using namespace std;

int ch[6]={500,100,50,10,5,1};
int n, cnt;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  n = 1000-n;
  for(int i=0;i<6;i++) cnt+=n/ch[i], n=n%ch[i];
  cout << cnt;
}