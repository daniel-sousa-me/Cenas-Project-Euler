#include <stdio.h>

int main()
{
  long m[20][20];
  FILE *f;
  f = fopen("11.matrix", "r");
  
  long i = 0;
  while(i<20) {
    long j = 0;
    while(j<20) {
      fscanf(f, "%ld", &m[i][j]);
      j++;
    }
    i++;
  }
  
  long r = 0;
  i = 0;
  while(i<20-3) {
    long j = 0;
    while(j<20-3) {
      long k = 0;
      long s1 = 1, s2 = 1, s3 = 1, s4 = 1;
      while(k<4) {
	s1 *= m[i+k][j];
	s2 *= m[i][j+k];
	s3 *= m[i+k][j+k];
	s4 *= m[i+3-k][j+k];
	k++;
      }
      if(s1>r) r = s1;
      if(s2>r) r = s2;
      if(s3>r) r = s3;
      if(s4>r) r = s4;
      j++;
    }
    i++;
  }

  printf("%ld\n", r);
}
