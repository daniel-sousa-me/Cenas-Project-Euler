#include <stdio.h>

void main()
{
  long max = 1, nmax = 0;
  long i = 2;

  while(i<=1000000) {
    long j = i, k = 0;
    while(j!=1) {
      if(j%2==0) {
	j = j/2;
      } else {
	j = 3*j+1;
      }
      k++;
    }
    if(k>nmax) {
      max = i;
      nmax = k;
    }
    i++;
  }

  printf("%ld\n", max);
}
