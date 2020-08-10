#include <stdio.h>

void pro() {
  char t[18];
  int sum = 0, i, a[18];

  scanf("%s", &t[1]);
  for(i=1 ; i<=16 ; i++) {
    if(i%2 == 0) sum+=t[i]-'0';
    else {
      a[i] = (t[i]-'0');
      a[i] *= 2;
      if(a[i]>=10) sum+=a[i]/10, sum+=a[i]%10;
      else sum+=a[i];
    }
  }
  
  if(sum%10 == 0) printf("T\n");
  else printf("F\n");
}

int main() {
  int k;
  scanf("%d", &k);
  while(k--) pro();
}