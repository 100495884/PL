#include <stdio.h>

main () {
  int i;
  int v[5];

  for (i = 0; i < 5; i = i + 1) {
    v[i] = i * 2;
  }

  for (i = 0; i < 5; i = i + 1) {
    printf("%d", v[i]);
  }
}
//@ (main)
