#include <stdio.h>

void pro() {
  int ah, am, as;
  int bh, bm, bs;

  scanf("%d %d %d %d %d %d", &ah, &am, &as, &bh, &bm, &bs);

  bs -= as;
  bm -= am;
  bh -= ah;

  if(bs < 0) {
    bs = (bs+60)%60;
    bm -= 1;
  }
  if(bm <0) {
    bm = (bm+60)%60;
    bh = (bh-1+24)%24;
  }

  printf("%d %d %d\n", bh, bm, bs);
}

int main() {
  pro();
  pro();
  pro();
}