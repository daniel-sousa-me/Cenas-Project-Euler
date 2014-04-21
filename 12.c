#include <stdio.h>
#include "divisors.h"

int main()
{
  generateDivisorsList(20000);

  FILE *f;
  f = fopen("divisors.list", "r");

  long i = 2;
  long aux1, aux2;
  while(i<=20000 && aux1*aux2<500) {
    rewind(f);
    if(i%2==0) {
      long j = 0;
      while(j<i/2) {
	fscanf(f, "%ld", &aux1);
	j++;
      }
      while(j<i+1) {
	fscanf(f, "%ld", &aux2);
	j++;
      }
    } else {
      long j = 0;
      while(j<(i+1)/2) {
	fscanf(f, "%ld", &aux1);
	j++;
      }
      while(j<i) {
	fscanf(f, "%ld", &aux2);
	j++;
      }
    }
    i++;
  }

  fclose(f);

  printf("%ld\n", i*(i-1)/2);
  return 0;
}
