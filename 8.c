#include <stdio.h>

void main() {
  FILE* f;
  f = fopen("8.list", "r");
  fseek(f,1,SEEK_SET);

  int l[5];
  char aux;
  int i = 0;
  while(i<5){
    fread(&aux,1,1,f);
    l[i] = aux - '0';
    i++;
  }
  fread(&aux,1,1,f);
  int r = product(l);
  while(aux!='\n') {
    int i = 1;
    while(i<5) {
      l[i-1] = l[i];
      i++;
    }
    l[4] = aux - '0';
    if(r<product(l))r = product(l);
    fread(&aux,1,1,f);
  }
  printf("O maior número é: %d\n",r);
}

int product(int* l) {
  int i = 0;
  int r = 1;
  while(i<5) {
    r *= l[i];
    i++;
  }
  return r;
}
