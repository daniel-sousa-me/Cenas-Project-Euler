#include <stdio.h>
#include <stdlib.h>
#include "huge_integers.h"

int main() {
  huge_int a = (huge_int)malloc(2*sizeof(long));
  huge_int r = (huge_int)malloc(400*sizeof(long));
  huge_int aux;
  a[0] = 2;
  a[1] = -1;
  r[0] = 2;
  r[1] = -1;

  long i = 1;
  while(i<1000) {
    aux = huge_product(a, r);
    huge_int_cpy(r, aux);
    free(aux);
    i++;
  }
  
  long s = 0;
  i = 0;
  while(r[i]!=-1) {
    s += r[i];
    i++;
  }
  
  printf("%ld\n", s);

  free(a);
  free(r);
  
  return 0;
}
