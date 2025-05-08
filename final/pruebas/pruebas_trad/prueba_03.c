#include <stdio.h>

mayor (int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

mayor3 (int x, int y, int z) {
  int m1;
  int resultado;
  m1 = mayor(x, y);
  resultado = mayor(m1, z);
  return resultado;
}

main () {
  int r;
  r = mayor3(4, 9, 7);
  printf("%d", r);
}
//@ (main)
