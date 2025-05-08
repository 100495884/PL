#include <stdio.h>

main () {
  int m[4];
  int i;
  int j;
  int pos;

  for (i = 0; i < 2; i = i + 1) {
    for (j = 0; j < 2; j = j + 1) {
      pos = i * 2 + j;
      m[pos] = i + j;
    }
  }

  for (i = 0; i < 2; i = i + 1) {
    for (j = 0; j < 2; j = j + 1) {
      pos = i * 2 + j;
      printf("%d", m[pos]);
    }
  }
}
//@ (main)
