#include <stdio.h>

long product(long* l) {
  long i = 0;
  long r = 1;
  while(i<5) {
    r *= l[i];
    i++;
  }
  return r;
}

int main()
{
  FILE *f;
  f = fopen("8.list", "r");
  fseek(f, 1, SEEK_SET);

  long l[5];
  char aux;
  long i = 0;
  while(i<5) {
    fread(&aux, 1, 1, f);
    l[i] = aux-'0';
    i++;
  }
  fread(&aux, 1, 1, f);
  long r = product(l);
  while(aux!='\n') {
    long i = 1;
    while(i<5) {
      l[i-1] = l[i];
      i++;
    }
    l[4] = aux-'0';
    if(r<product(l)) r = product(l);
    fread(&aux, 1, 1, f);
  }

  printf("%ld\n", r);
  return 0;
}
