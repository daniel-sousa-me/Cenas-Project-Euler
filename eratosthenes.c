#include <stdio.h>
#include "stack.h"

/*void main(int argc, char **argv){
  int n = atoi(argv[1]);
  generateEratosthenes(n);
  stack s = eratosthenesPrimes(n);
  while(s->size!=0){
    printf("%d\n",pop(s));
  }
}*/

void generateEratosthenes(long n){
  FILE *f;
  f = fopen("eratosthenes.list", "w+");
  long i = 0;
  while(i<n){
    fprintf(f,"1");
    i++;
  }
  i = 2;
  char b;
  while(i<=n){
    rewind(f);
    fseek(f,i-1,SEEK_SET);
    fread(&b,1,1,f);
    if(b=='1'){
      while(ftell(f)<=n-i){
        fseek(f,i-1,SEEK_CUR);
        fprintf(f,"0");
      }
    }
    i++;
  }
  fclose(f);
}

int eratosthenesPrimeQ(int n) {
  FILE *f;
  f = fopen("eratosthenes.list", "r");
  char b;
  fseek(f,n-1,SEEK_SET);
  fread(&b,1,1,f);
  return atoi(&b);
}

stack eratosthenesPrimes(int n) {
  FILE* f;
  f = fopen("eratosthenes.list", "r");
  fseek(f,1,SEEK_SET);
  
  stack s = newStack();
  int i = 2;
  char aux;
  while(i<=n) {
    fread(&aux,1,1,f);
    if(aux=='1') push(s,i);
    i++;
  }
  fclose(f);
  return s;
}

int eratosthenesPrime(int n) {
  FILE* f;
  f = fopen("eratosthenes.list", "r");
  fseek(f,1,SEEK_SET);
  
  int i = 1;
  int j = 1;
  char aux;
  while(j<=n) {
    fread(&aux,1,1,f);
    if(aux=='1') j++;
    i++;
  }
  fclose(f);
  return i;
}
