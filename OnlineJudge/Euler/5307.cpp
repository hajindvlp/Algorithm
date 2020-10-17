#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100000
#define X first
#define Y second
using namespace std;

struct food {
  int first;
  int second;
};

bool comp(food x, food y) {
  if(x.X < y.X) return true;
  if(x.X == y.X && x.Y < y.Y) return true;
  return false;
}

int N, M, sum;
bool v[MAX+5];
vector<food> A, B;

int main() {
  int i, j, x, y;

  cin >> N >> M;
  for(i=0 ; i<N ; i++) cin >> x >> y, A.push_back({x, y});
  for(i=0 ; i<M ; i++) cin >> x >> y, B.push_back({x, y});

  if(M < N) {
    cout << -1;
    return 0;
  }

  sort(A.begin(), A.end(), comp);
  sort(B.begin(), B.end(), comp);
  j = 0;
  for(i=0 ; i<N ; i++) {
    bool flag = false;
    for(; j<M ; j++) 
      if(A[i].X <= B[j].X && A[i].Y <= B[j].Y) {
        flag = true;
        break;
      }

    if(!flag) {
      cout << -1;
      return 0;
    }

    sum += B[j].first;
    j++;
  }
  cout << sum;
}