#include <iostream>
using namespace std;

int py[2]={1, 1}, px[2]={1, -1};
int ry[4]={1, 0, -1, 0}, rx[4]={0, 1, 0, -1};
int by[4]={-1, 1, 1, -1}, bx[4]={1, 1, -1, -1};
int qy[8]={0, 1, 1, 1, 0, -1, -1, -1}, qx[8]={1, 1, 0, -1, -1, -1, 0, 1};
int ky[8]={0, 1, 1, 1, 0, -1, -1, -1}, kx[8]={1, 1, 0, -1, -1, -1, 0, 1};
int ny[8]={-2, -1, 1, 2, 2, 1, -1, -2}, nx[8]={1, 2, 2, 1, -1, -2, -2, -1};

int pro() {
  int board[9][9], i, j, bw[9][9];
  string s;

  for(i=1 ; i<=8 ; i++) {
    cin >> s;
    for(j=1 ; j<=8 ; j++) {
      if('A' <= s[j] && s[j] <= 'Z') s[j] -= 'A', bw[i][j] = 1;
      if('a' <= s[j] && s[j] <= 'z') s[j] -= 'a', bw[i][j] = 0;
      if(s[j] == '.') board[i][j] = -1, bw[i][j] = -1;

      if(bw[i][j] != -1) board[i][j] = s[j];
    }
  }

  for(i=1 ; i<=8 ; i++) {
    for(j=1 ; j<=8 ; j++) {
      if(board[])
    }
  }
}

int main() {
  pro();
  pro();
}