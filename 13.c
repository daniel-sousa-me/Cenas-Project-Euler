#include <stdio.h>
#include <stdlib.h>
#include "huge_integers.h"

void main() {
  FILE *f;
  f = fopen("13.list","r");
  
  huge_int l[100];
  int i = 0;
  while(i<100) {
    l[i] = (huge_int)malloc(100*sizeof(int));
    i++;
  }
  i = 0;
  while(i<100) {
    char s[51];
    fscanf(f,"%s",s);
    int j = 0;
    while(j<50) {
      l[i][j] = 0;
      j++;
    }
    while(j<100) {
      l[i][j] = s[j-50] - '0';
      j++;
    }
    i++;
  }

  huge_int r = (huge_int)malloc(100*sizeof(int)), aux = (huge_int)malloc(100*sizeof(int));
  copy_huge_int(100,l[0],r);
  i = 1;
  while(i<100) {
    copy_huge_int(100,r,aux);
    huge_sum(100,aux,l[i],r);
    i++;
  }
  
  printf("A soma é: ");
  print_huge_int(100,r);
  printf("\n");
}
