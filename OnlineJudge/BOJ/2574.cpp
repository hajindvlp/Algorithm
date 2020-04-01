#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <map>
#define INF 100000000

using namespace std;

struct Square {
  int c, x1, y1, x2, y2;
};

struct Node {
  struct Square data;
  struct Node* c1;
  struct Node* c2;
};

map<int, struct Square> Leaf;
struct Node tree;
int n, m, k;
int mx, mn = INF;

int size(struct Square ts) {
  return (ts.x2-ts.x1)*(ts.y2-ts.y1);
}

struct Node* newNode(struct Square data) {
  struct Node* node = new struct Node();

  node->data = data;
  node->c1 = NULL;
  node->c2 = NULL;
  return node;
}

void rec(struct Node* node) {
  int s;
  if(node->c1 == NULL && node->c2 == NULL) {
    s = size(node->data);
    mx = (s>mx) ? s : mx;
    mn = (s<mn) ? s : mn;
  }
  else {
    rec(node->c1);
    rec(node->c2);
  }
}

int main() {
  int i, j;
  int x, y;
  struct Node* ts;

  scanf("%d %d %d", &n, &m, &k);
  tree.data = {0, 0, 0, n, m};

  for(i=1 ; i<=k ; i++) {
    scanf("%d %d", &x, &y);
    ts = &tree;
    
    while(1) {
      if(y > ts->data.y1 && y < ts->data.y2 && x > ts->data.x1 && x < ts->data.x2 && ts->c1 == NULL && ts->c2 == NULL) {
        if(ts->data.c) {
          ts->c1 = newNode({0, x, ts->data.y1, ts->data.x2, ts->data.y2});
          ts->c2 = newNode({0, ts->data.x1, ts->data.y1, x, ts->data.y2});
        } else {
          ts->c1 = newNode({1, ts->data.x1, y, ts->data.x2, ts->data.y2});
          ts->c2 = newNode({1, ts->data.x1, ts->data.y1, ts->data.x2, y});
        }
        break;
      } else {
        if(y > ts->c1->data.y1 && y < ts->c1->data.y2 && x > ts->c1->data.x1 && x < ts->c1->data.x2)
          ts = ts->c1;
        else ts = ts->c2;
      }
    }
  }
  rec(&tree);
  printf("%d %d", mx, mn);
}