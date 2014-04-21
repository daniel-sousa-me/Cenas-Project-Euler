#include <stdio.h>

int main()
{
  long a=0, b=1;
  long s=0;

  while(b<4000000) {
    if(b%2==0) s += b;
    b = a+b;
    a = b-a;
  }

  printf("%ld\n", s);
}
