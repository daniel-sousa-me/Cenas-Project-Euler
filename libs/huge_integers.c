#include <stdio.h>
#include "huge_integers.h"

void copy_huge_int(long s, huge_int a, huge_int b)
{
  long i = 0;
  while(i<s) {
    b[i] = a[i];
    i++;
  }
}

void huge_sum(long s, huge_int a, huge_int b, huge_int r)
{
  long i = s-1;
  r[s-1] = 0;
  while(i>=0) {
    r[i] += a[i]+b[i];
    if(i>0)r[i-1] = r[i]/10;
    r[i] = r[i]%10;
    i--;
  }
}

void huge_product(long s, huge_int a, huge_int b, huge_int r)
{
  long i = s-1;
  r[s-1] = 0;
  while(i>=0) {
    long j = 0, aux = 0;
    while(j<s-i) {
      aux += a[s-j-1]*b[i+j];
      j++;
    }
    r[i] += aux;
    if(i>0) r[i-1] = r[i]/10;
    r[i] = r[i]%10;
    i--;
  }
}

void print_huge_int(long s, huge_int a)
{
  long i = 0;
  int b = 0;
  while(i<s) {
    if(b || a[i]) {
      printf("%ld", a[i]);
      b = 1;
    }
    i++;
  }
}
