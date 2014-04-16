# include <stdio.h>
# include "palindromeQ.h"

void main() {
  int i = 100;
  long r = 0;
  while(i<1000){
    int j=i;
    while(j<1000){
      if(i*j>r && palindromeQ(i*j))r = i*j;
      j++;
    }
    i++;
  }
  printf("%d\n",r);
}
