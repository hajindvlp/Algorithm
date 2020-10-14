#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, A, B, temp, ans;
priority_queue<int, vector<int>, less<int>> AA, BB;
vector<int> v;

int main(){
  ios_base::sync_with_stdio(false); 
  cout.tie(NULL); 
  cin.tie(NULL);

  cin >> N >> A >> B;
  temp = N;

  for (int i = 0; i < A; ++i){
    int num;
    cin >> num;
    AA.push(num);
  }

  for (int i = 0; i < B; ++i){
    int num;
    cin >> num;
    BB.push(num);
  }

  for (int i = 0; i < B; ++i){
    if(temp<2) break;
    v.push_back(BB.top());
    temp-=2;
    BB.pop();
  }

  while(temp>0){
    ans+=AA.top();
    AA.pop();
    temp--;
  }

  for (int i = v.size()-1; i >=0 ; i--){
    if(AA.size()<2) break;
    int a1 = AA.top();
    AA.pop();
    int a2 = AA.top();
    AA.pop();

    if(a1+a2>v[i]) v[i]=a1+a2;
    else break;
  }

  for (int i = 0; i < v.size(); ++i)
    ans += v[i];

  cout << ans << '\n';

  return 0;
}