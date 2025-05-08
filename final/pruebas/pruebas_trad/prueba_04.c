#include <stdio.h>

main () {
  int x;
  int resto;
  int distinto_cero;
  int condicion;

  x = 10;
  resto = x % 2;

  if (x != 0) {
    distinto_cero = 1;
  } else {
    distinto_cero = 0;
  }

  if (resto == 0) {
    if (distinto_cero == 1) {
      condicion = 1;
    } else {
      condicion = 0;
    }
  } else {
    condicion = 0;
  }

  if (condicion == 1) {
    puts("Es par y no cero");
  } else {
    puts("No cumple");
  }
}
//@ (main)
