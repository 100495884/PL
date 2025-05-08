#include <stdio.h>


main () {
  int i;
  for (i = 0; i < 5; i = i + 1) {
    if (i == 2) {
      puts("salto");
    } else {
      printf("%d", i);
    }
  }
}
//@ (main)
