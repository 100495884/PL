#include <stdio.h>

int v[3];

suma () {
  int resultado;
  resultado = v[0] + v[1] + v[2];
  return resultado;
}

main () {
  int r;
  v[0] = 10;
  v[1] = 20;
  v[2] = 30;
  r = suma();
  printf("%d", r);
}
//@ (main)
