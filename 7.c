#include <stdio.h>
#include "stack.h"
#include "eratosthenes.h"

void main()
{
  generateEratosthenes(107300);
  printf("%ld\n", eratosthenesPrime(10001));
}
