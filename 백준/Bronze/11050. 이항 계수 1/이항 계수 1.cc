#include <stdio.h>

int fac(int n){
  if(n == 1 || n == 0)
  {
      return (1);
  }
  
  return (fac(n - 1) * n);
}


int main(){

  int n = 0, k = 0;

  scanf("%d %d", &n, &k);

  printf("%d", fac(n)/(fac(n - k) * fac(k)));

  return 0;
}

// 이항계수
// n k = nCk = n!/(n-k)!k!