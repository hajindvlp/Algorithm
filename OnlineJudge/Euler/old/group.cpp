#include<stdio.h>
#define NMAX 105
int n;
int cnt=1;     // 그룹의 수.
int check[NMAX];   // 몇번째 그룹에 속해있는가 판별.
int table[NMAX][NMAX];  // 입력받을 테이블.
bool Group_Check() {
 int i,j,k;
 int people;
 for( i = 1; i <= n; i++ ) {
  if( check[i] == 0 ) {
   people = 1;
   check[i] = cnt;
   for( j = 1; j <= n; j++ ) {
    if( i == j )
     continue;
    if( table[i][j] == 0 ) {
     for( k = 1; k <= n; k++ ) {
      if( table[i][k] != table[j][k] )
       return 0;
     }
     check[j] = cnt;
     people++;
    }
   }
   if( people == 1 )
    return 0;
   cnt++;
  }
 }
 return true;
}
int main() {
 int i,j;
 scanf("%d",&n);
 for( i = 1; i <= n; i++ ) {
  for( j = 1; j <= n; j++ )
   scanf("%d",&table[i][j]);
 }
 if(!Group_Check())
  printf("%d\n",0);
 else {
  printf("%d\n",cnt-1);
  for( i = 1; i <= cnt; i++ ) {
   for( j = 1; j <= n; j++ ) {
    if( check[j] == i )
     printf("%d ",j);
   }
   printf("\n");
  }
 }
 return 0;
}
