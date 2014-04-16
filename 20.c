#include <stdio.h>
#include <stdlib.h>
#include "huge_integers.h"

void main() {
  huge_int r = (huge_int)malloc(200*sizeof(int));
  huge_int r_aux = (huge_int)malloc(200*sizeof(int));
  huge_int huge_i = (huge_int)malloc(200*sizeof(int));
  huge_int huge_i_aux = (huge_int)malloc(200*sizeof(int));
  huge_int aux = (huge_int)malloc(200*sizeof(int));
  r[199] = 1;
  huge_i[199] = 1;
  aux[199] = 1;
  int i = 0;
  while(i<199) {
    r[i] = 0;
    huge_i[i] = 0;
    aux[i] = 0;
    i++;
  }
  
  i = 1;
  while(i<=100) {
    copy_huge_int(200,r,r_aux);
    huge_product(200,r_aux,huge_i,r);
    copy_huge_int(200,huge_i,huge_i_aux);
    huge_sum(200,huge_i_aux,aux,huge_i);
    i++;
  }
  
  i = 0;
  long s = 0;
  while(i<200) {
    s += r[i];
    i++;
  }

  printf("O resultado é %ld\n", s);
}
