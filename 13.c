#include <stdio.h>
#include <stdlib.h>
#include "huge_integers.h"

int main()
{
  FILE *f;
  f = fopen("13.list", "r");
  
  huge_int r = (huge_int)malloc(100*sizeof(long));
  huge_int aux1 = (huge_int)malloc(51*sizeof(long));
  huge_int aux2;
  long i = 0;
  r[0] = -1;
  
  while(i<100) {
    char s[51];
    fscanf(f, "%s", s);
    long j = 0;
    while(j<50) {
      aux1[49-j] = s[j]-'0';
      j++;
    }
    aux1[50] = -1;
    aux2 = huge_sum(r, aux1);
    huge_int_cpy(r, aux2);
    free(aux2);
    i++;
  }

  print_huge_int(r);
  printf("\n");

  free(r);
  free(aux1);
  fclose(f);
  
  return 0;
}
