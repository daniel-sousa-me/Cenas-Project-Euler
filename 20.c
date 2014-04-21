#include <stdio.h>
#include <stdlib.h>
#include "huge_integers.h"

int main() {
  huge_int r = (huge_int)malloc(200*sizeof(long));
  huge_int r_aux;
  huge_int huge_i = (huge_int)malloc(200*sizeof(long));
  huge_int huge_i_aux;
  huge_int aux = (huge_int)malloc(2*sizeof(long)); //Always 1

  r[0] = 1;
  r[1] = -1;
  huge_i[0] = 1;
  huge_i[1] = -1;
  aux[0] = 1;
  aux[1] = -1;

  long i = 1;
  while(i<=100) {
    r_aux = huge_product(r, huge_i);
    huge_int_cpy(r, r_aux);
    free(r_aux);
    huge_i_aux = huge_sum(huge_i, aux);
    huge_int_cpy(huge_i, huge_i_aux);
    free(huge_i_aux);   
    i++;
  }
  
  i = 0;
  long s = 0;
  while(r[i]!=-1) {
    s += r[i];
    i++;
  }

  printf("%ld\n", s);

  free(r);
  free(huge_i);
  free(aux);
  
  return 0;
}
