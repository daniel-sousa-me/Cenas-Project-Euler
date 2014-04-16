#include <stdio.h>

void main() {
  FILE *f;
  f = fopen("67.triangle","r");
  
  int s[100];
  fscanf(f, "%d", &s[0]);
  int i = 1;
  while(i<100) {
    int aux[i+1];
    int j = 0;
    while(j<=i) {
      fscanf(f, "%d", &aux[j]);
      j++;
    }
    j = i-1;
    s[i] = s[i-1] + aux[i];
    while(j>0) {
      if(s[j-1]>s[j]) {
	s[j] = s[j-1] + aux[j];
      } else {
	s[j] = s[j] + aux[j];
      }
      j--;
    }
    s[0] = s[0] + aux[0];

    /*
    j = 0;
    while(j<=i) {
      printf("%d ", s[j]);
      j++;
    }
    printf("\n");
    */

    i++;
  }

  i = 1;
  int r = s[0];
  while(i<100) {
    if(s[i]>r) r = s[i];
    i++;
  }

  printf("O resultado é %d\n", r);
  fclose(f);
}
