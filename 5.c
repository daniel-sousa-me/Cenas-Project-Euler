#include <stdio.h>
#include "stack.h"
#include "eratosthenes.h"

void main() {
  int n = 20;
  generateEratosthenes(n);
  stack p = eratosthenesPrimes(n);

  int r = 1;
  while(p->size > 0) {
    int q = p->last->val;
    while(q*p->last->val <= n){
      q *= p->last->val;
    }
    r *= q;
    pop(p);
  }
  printf("%d\n",r);
}
