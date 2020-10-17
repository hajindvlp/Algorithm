#include <stdio.h>
using namespace std;

int main(){
   char c[201][201];
   int r, s, a, b;

   scanf("%d%d", &r, &s);

   for (int i=0; i<r; i++){
      for (int j=0; j<s; j++){
         scanf(" %c", &c[i][j]);
         c[2*r-i-1][j] = c[i][2*s-j-1] = c[2*r-i-1][2*s-j-1] = c[i][j];
      }
   }

   scanf("%d%d", &a, &b);
   c[a-1][b-1] = c[a-1][b-1] == '#' ? '.' : '#';

   for (int i=0; i<2*r; i++) {
      c[i][2*s] = '\0';
      printf("%s\n", c[i]);
   }

   return 0;
}
