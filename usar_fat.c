#include <stdio.h>
#include "bibli.h"

int main(){

  int n;

  scanf("%d", &n);

  while(n < 0){
    printf("Digite um numero maior que 0\n");
    scanf("%d", &n);
  }

  printf("%d\n", fatorial(n));

}
