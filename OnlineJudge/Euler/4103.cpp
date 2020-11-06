#include <iostream>
#include <string>
using namespace std;

int N;

struct node {
  int val;
  node *l, *r;
};

node *root, *tmp;

int main() {
  int i, j;
  int x;
  bool flag = false, isRoot = false;
  string s;

  cin >> N;
  for(i=1 ; i<=N ; i++) {
    if(i!=N) {
      if(flag) {
        x = stoi(s);
        cin >> s;
        flag = false;
        isRoot = true;
      } else {
        cin >> x >> s;
        if(s[0]!='L' || s[0]!='R') flag = true;
      }
    } else {
      if(isRoot) cin >> x >> s;
      else cin >> x;
    }

    int len = s.size();
    tmp = root;
    for(j=0 ; j<len ; j++) {
      if(s[j] == 'L') {
        if(tmp -> l == NULL) tmp -> l = new node;
        cout << len;
        tmp = tmp -> l;
      } else {
        if(tmp -> r == NULL) tmp -> r = new node;
        tmp = tmp -> r;
      }
    }
    tmp -> val = x;
  }
}