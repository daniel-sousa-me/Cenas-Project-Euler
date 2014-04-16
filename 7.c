#include <stdio.h>
#include "stack.h"
#include "eratosthenes.h"

void main() {
  generateEratosthenes(107300);
  printf("O 10001º primo é %d\n",eratosthenesPrime(10001));
}
