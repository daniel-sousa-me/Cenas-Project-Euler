int palindromeQ(long n) {
  int l = 1;
  int i = n;
  while(i>=10){
    l++;
    i = i/10;
  }
  int v[l];
  i = l-1;
  while(i>=0){
    v[i]=n%10;
    i--;
    n = n/10;
  }
  i=0;
  while(i<=(l+1)/2){
    if(v[i]!=v[l-i-1]) return 0;
    i++;
  }
  return 1;
}
