#include <stdio.h>

void main()
{
  long n = 600851475143;
  long i = 3;

  while(i*i<n) {
    while(n%i==0) {
      n = n/i;
    }
    i += 2;
  }

  printf("%ld\n", n);
}
