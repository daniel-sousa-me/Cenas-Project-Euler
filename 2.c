#include <stdio.h>

void main() {
  int a=0,b=1;
  int s=0;
  while(b<4000000) {
    if(b%2==0) s+=b;
    b = a + b;
    a = b - a;
  }
  printf("%d\n",s);
}
