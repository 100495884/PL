#include <stdio.h>

suma_pares (int n) {
  if (n == 0) {
    return 0;
  } else {
    if (n % 2 == 0) {
      return n + suma_pares(n - 1);
    } else {
      return suma_pares(n - 1);
    }
  }
}

main () {
  int resultado;
  resultado = suma_pares(10);
  printf("%d", resultado);
}
//@ (main)
