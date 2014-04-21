#include <stdio.h>
#include "palindromeQ.h"

int main()
{
  long i = 100;
  long r = 0;

  while(i<1000) {
    long j = i;
    while(j<1000) {
      if(i*j>r && palindromeQ(i*j)) r = i*j;
      j++;
    }
    i++;
  }

  printf("%ld\n", r);
  return 0;
}
