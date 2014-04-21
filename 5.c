#include <stdio.h>
#include "stack.h"
#include "eratosthenes.h"

int main()
{
  long n = 20;
  generateEratosthenes(n);
  stack p = eratosthenesPrimes(n);

  long r = 1;
  while(p->size>0) {
    long q = p->last->val;
    while(q*p->last->val<=n) {
      q *= p->last->val;
    }
    r *= q;
    pop(p);
  }

  printf("%ld\n", r);
  return 0;
}
