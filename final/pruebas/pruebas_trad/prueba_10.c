#include <stdio.h>


cuadrado (int x) {
  return x * x;
}


suma_cuadrados (int a, int b) {
  int resultado;
  resultado = cuadrado(a) + cuadrado(b);
  return resultado;
}


main () {
  int r;
  r = suma_cuadrados(3, 4);
  printf("%d", r);
}
//@ (main)
