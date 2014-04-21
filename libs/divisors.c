#include <stdio.h>

void generateDivisorsList(long n) {
  FILE *f;
  f = fopen("divisors.list", "w+");

  long i = 0;
  while(i<n) {
    fprintf(f, "0000000001\n");
    i++;
  }

  i = 2;
  long auxn = 0;
  while(i<=n) {
    long j = 0;
    rewind(f);
    while(j<=1 || j<i) {
      fscanf(f, "%ld", &auxn);
      j++;
    }
    while(auxn!=1 && i<n) {
      fscanf(f, "%ld", &auxn);
      j++;
      i++;
    }

    if(auxn==1) {
      while(j<=n) {;
	long k = 0;
	long j2 = j;
	while(j2%i==0) {
	  j2 = j2/i;
	  k++;
	}
	auxn *= k+1;
	long auxn2 = auxn;
	k = 1;
	while(auxn2>9) {
	  auxn2 = auxn2/10;
	  k++;
	}
	fseek(f,-k,SEEK_CUR);
	fprintf(f, "%ld", auxn);
	k = 0;
	while(k<i) {
	  fscanf(f, "%ld", &auxn);
	  k++;
	  j++;
	}
      }
    }
    i++;
  }
  fclose(f);
}
