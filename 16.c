#include <stdio.h>
#include <stdlib.h>
#include "huge_integers.h"

int main() {
  huge_int n1 = (huge_int)malloc(400*sizeof(long));
  huge_int n2 = (huge_int)malloc(400*sizeof(long));
  huge_int n3 = (huge_int)malloc(400*sizeof(long));
  
  long i = 0;
  while(i<400) {
    n1[i] = 0;
    n2[i] = 0;
    n3[i] = 0;
    i++;
  }
  n1[399] = 2;

  i = 1;
  while(i<1000) {
    copy_huge_int(400, n1, n2);
    huge_sum(400, n1, n2, n3);
    copy_huge_int(400, n3, n1);
    i++;
  }
  
  long r = 0;
  i = 0;
  while(i<400) {
    r += n1[i];
    i++;
  }
  
  printf("%ld\n", r);
  return 0;
}
