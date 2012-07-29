#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
main()
{
  time_t t;
  int i,n;
  n = 10000000;
  t = clock();
  for(i = 0; i < n; ++i){
    sqrt(10.0);
  }
  t = clock() - t;
  printf("%ld\n",t);
}