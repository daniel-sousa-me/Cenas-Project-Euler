#include <stdio.h>
#include "stack.h"
#include "eratosthenes.h"

void main()
{
  generateEratosthenes(2000000);
  FILE *f;
  f = fopen("eratosthenes.list", "r");
  fseek(f,1,SEEK_SET);
  
  long i = 2;
  long r = 0;
  char aux;
  while(i<2000000) {
    fread(&aux, 1, 1, f);
    if(aux=='1') r += i;
    i++;
  }

  printf("%ld\n", r);
}
