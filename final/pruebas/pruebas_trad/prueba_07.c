#include <stdio.h>

doble (int x) {
  return x * 2;
}

triple (int x) {
  int r;
  r = doble(x);
  return r + x;
}

main () {
  int r;
  r = triple(4);
  printf("%d", r);
}
//@ (main)
