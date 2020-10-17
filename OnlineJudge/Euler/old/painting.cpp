#include <iostream>
#include <string>
using namespace std;

bool paint[50005][20];
int iseg[200000][80], fseg[200000][80];

int N, M, Q;

int finalSeg(int l, int h, int pos) {
  if(l == h) {
    for(int i=1 ; i<2*M ; i++) {
      fseg[pos][i] = iseg[l][i];
    }
  } else {
    int m = (h+1) >> 1;
    finalSeg(l, m, 2*pos);
    finalSeg(m+1, h, 2*pos+1);
    for(int i=1 ; i<2*M ; i++) {
      fseg[pos][i] = fseg[pos*2][i]+fseg[pos*2+1][i];
    }
  }
}

int seg(int l, int h, int pos, int strip) {
  if(h == l) {
    iseg[strip][pos] = paint[strip][l];
  } else {
    int m = (h+l) >> 1;
    seg(l, m, 2*pos, strip);
    seg(m+1, h, 2*pos+1, strip);
    iseg[strip][pos] = iseg[strip][pos*2]+iseg[strip][pos*2+1]; 
  }
}

int fQuery(int pos, int s, int e, int x1, int x2, int node) {
  if(x2 < s || e < x1) {
    return 0;
  }

  if(x1 <= s && e <= x2) {
    return fseg[node][pos];
  }

  int m = (s+2) >> 1;
  int p1 = fQuery(2*pos, s, m, x1, x2, node); 
  int p2 = fQuery(2*pos+1, m+1, e, x1, x2, node); 
  return (p1+p2);
}

int query(int pos, int s, int e, int y1, int y2, int x1, int x2) {
  if (y2 < s || e < y1) { 
    return 0; 
  } 
  
  if (y1 <= s && e <= y2) { 
    return (fQuery(1, 1, 4, x1, x2, pos)); 
  } 

  int m = (s+e) >> 1; 
  int p1 = query(2*pos, s, m, y1, y2, x1, x2); 
  int p2 = query(2*pos+1, m+1, e, y1, y2, x1, x2); 
  return (p1+p2); 
} 

int fUpdate(int pos, int l, int h, int x, int val, int node) 
{ 
  if (l == h) { 
    fseg[node][pos] = val; 
  } 
  else { 
    int mid = (l+h) >> 1; 
    if (l <= x && x <= mid) { 
      fUpdate(2*pos, l, mid, x, val, node); 
    } 
    else { 
      fUpdate(2*pos+1, mid+1, h, x, val, node); 
    } 
    fseg[node][pos] = fseg[node][2*pos]+fseg[node][2*pos+1]; 
  } 
} 

int update(int pos, int l, int h, int x, int y, int val) 
{ 
  if (l == h) { 
    fUpdate(1, 1, 4, x, val, pos); 
  } 
  else { 
    int mid = (l+h) / 2; 
    if (l <= y && y <= mid) { 
      update(2*pos, l, mid, x, y, val); 
    } 
    else { 
      update(2*pos+1, mid+1, h, x, y, val); 
    } 
    for (int i = 1; i < M; i++) 
      fseg[pos][i] = fseg[2*pos][i]+fseg[2*pos+1][i]; 
  } 
} 

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int i, j, r1, r2, c1, c2, v;
  string s;
  cin >> N >> M >> Q;
  for(i=0 ; i<N ; i++) {
    cin >> s;
    for(j=0 ; j<M ; j++)
      paint[i][j] = s[j] == '1';
  }


  for(i=1 ; i<=Q ; i++) {
    cin >> r1 >> r2 >> c1 >> c2 >> v;
    update()
  }
}