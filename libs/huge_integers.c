#include <stdio.h>
#include <stdlib.h>
#include "huge_integers.h"

long huge_int_length(huge_int a)
{
  long l = 0;
  while(a[l]!=-1) {
    l++;
  }
  return l;
}

huge_int huge_sum(huge_int a, huge_int b)
{
  long l1 = huge_int_length(a);
  long l2 = huge_int_length(b);
  long l;
  if(l1>l2) l = l1;
  else l = l2;
  huge_int r = (huge_int)malloc((l+2)*sizeof(r));
  
  long i = 0;
  r[0] = 0;
  while(i<l1 || i<l2) {
    if(i<l1 && i<l2) r[i] += a[i]+b[i];
    if(i>=l1) r[i] += b[i];
    if(i>=l2) r[i] += a[i];
    r[i+1] = r[i]/10;
    r[i] = r[i]%10;
    i++;
  }
  if(r[i]>0) i++;
  r[i] = -1;

  return r;
}

huge_int huge_product(huge_int a, huge_int b)
{
  long l1 = huge_int_length(a);
  long l2 = huge_int_length(b);
  long l = l1+l2;
  huge_int r = (huge_int)malloc((l+1)*sizeof(r));

  long i = 0;
  r[0] = 0;
  while(i<l1+l2-1) {
    long j = 0, aux = 0;
    if(i>=l1) j = i-l1+1;
    while(j<=i && j<l2) {
      aux += a[i-j]*b[j];
      j++;
    }
    r[i] += aux;
    r[i+1] = r[i]/10;
    r[i] = r[i]%10;
    i++;
  }
  if(r[i]>0) i++;
  r[i] = -1;
  
  return r;
}

void huge_int_cpy(huge_int a, huge_int b)
{
  long i = huge_int_length(b);
  while(i>=0) {
    a[i] = b[i];
    i--;
  }
}

void print_huge_int(huge_int a)
{
  long i = huge_int_length(a);
  while(i>0) {
    i--;
    printf("%ld", a[i]);
  }
}
