#include <stdio.h>
#include "stack.h"
#include "eratosthenes.h"

int main()
{
  generateEratosthenes(107300);
  printf("%ld\n", eratosthenesPrime(10001));
  return 0;
}
