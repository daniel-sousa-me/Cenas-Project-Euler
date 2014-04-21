#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void generateEratosthenes(long n)
{
  FILE *f;
  f = fopen("eratosthenes.list", "w+");
  long i = 0;
  while(i<n) {
    fprintf(f, "1");
    i++;
  }

  i = 2;
  char b;
  while(i<=n) {
    rewind(f);
    fseek(f, i-1, SEEK_SET);
    fread(&b, 1, 1, f);
    if(b=='1') {
      while(ftell(f)<=n-i) {
        fseek(f, i-1, SEEK_CUR);
        fprintf(f, "0");
      }
    }
    i++;
  }
  
  fclose(f);
}

int eratosthenesPrimeQ(long n)
{
  FILE *f;
  f = fopen("eratosthenes.list", "r");
  char b;
  fseek(f, n-1, SEEK_SET);
  fread(&b, 1, 1, f);
  return atoi(&b);
}

stack eratosthenesPrimes(long n)
{
  FILE* f;
  f = fopen("eratosthenes.list", "r");
  fseek(f, 1, SEEK_SET);
  
  stack s = newStack();
  long i = 2;
  char aux;
  while(i<=n) {
    fread(&aux, 1, 1, f);
    if(aux=='1') push(s, i);
    i++;
  }
  fclose(f);
  return s;
}

long eratosthenesPrime(int n)
{
  FILE* f;
  f = fopen("eratosthenes.list", "r");
  fseek(f, 1, SEEK_SET);
  
  long i = 1;
  long j = 1;
  char aux;
  while(j<=n) {
    fread(&aux, 1, 1, f);
    if(aux=='1') j++;
    i++;
  }
  fclose(f);
  return i;
}
