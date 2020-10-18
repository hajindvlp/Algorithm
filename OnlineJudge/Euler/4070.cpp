#include <iostream>
using namespace std;

void pro() {
  bool visit[3005];
  long long N, x, y, i;

  cin >> N;
  for(i=1 ; i<N ; i++) visit[i] = false;
  cin >> x;
  for(i=2 ; i<=N ; i++) {
    cin >> y;
    if(abs(x-y) < N) visit[abs(x-y)] = true;
    x = y;  
  }
  for(i=1 ; i<N ; i++) if(!visit[i]) {
    cout << "Not Jolly \n";
    return;
  }
  cout << "Jolly\n";
}

int main() {
  pro();
  pro();
}