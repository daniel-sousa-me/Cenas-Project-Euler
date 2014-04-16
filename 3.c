# include <stdio.h>

void main() {
  long n = 600851475143;
  int i = 3;
  while(i*i<n){
    while(n%i==0){
      n = n/i;
      printf("%d\n",i);
    }
    i += 2;
  }
  printf("\nResposta:%d\n",n);
}
