#include <stdio.h>

char *k = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

main(){
   int i,c;
   while (EOF != (c = getchar())) {
      for (i=1;k[i] && k[i]!=c;i++);
      if (k[i]) putchar(k[i-1]); else putchar(c);
   }
}
