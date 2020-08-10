#include <stdio.h>

int s[5][10];
int acase[97][10];
int dict[27];

int main() {
  int i, j;
  char tmp[10];
  int t[10];
  int x;

  dict['R'-'A'+1] = 1;
  dict['G'-'A'+1] = 2;
  dict['B'-'A'+1] = 3;
  dict['Y'-'A'+1] = 4;

  for(i=1 ; i<=4 ; i++) {
    scanf("%s", &tmp[1]);
    for(j=1 ; j<=6 ; j++) s[i][j] = dict[tmp[j]-'A'+1];
    for(j=1 ; j<=6 ; j++) {
      for(k=1 ; k<=4 ; k++) {
        x = t[1];
        t[1] = s[i][2];
        t[2] = s[i][3];
        t[3] = s[i][4];
        t[4] = x;
        
      }
    }
  }
}