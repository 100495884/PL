#include <stdio.h>

main () {
  int i;
  for (i = 5; i > 0; i = i - 1) {
    printf("%d", i);
    if (i == 3) {
      puts("mitad");
    }
  }
}
//@ (main)
