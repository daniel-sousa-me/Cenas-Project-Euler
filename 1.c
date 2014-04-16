# include <stdio.h>

void main() {
  int i=1;
  int r=0;
  while(i<1000){
    if(i%3==0 || i%5==0){
      r += i;
    }
    i++;
  }
  printf("%d\n",r);
}
