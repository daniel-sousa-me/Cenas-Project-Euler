#include <stdio.h>

void main()
{
  long i = 1;
  long r = 0;

  while(i<1000) {
    if(i%3==0 || i%5==0) {
      r += i;
    }
    i++;
  }

  printf("%ld\n", r);
}
