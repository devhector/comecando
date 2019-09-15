#include <stdio.h>

int fatorial (int x){
  
  if (x == 0 || x == 1)
    return 1;
  else
    return fatorial(x-1)*x;

}
