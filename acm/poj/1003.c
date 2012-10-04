#include <stdio.h>

main()
{
  double t;
  double sum;
  int i;
  do{
    scanf("%lf",&t);
    if(t < 0.01) break;
    sum = 0;
    for(i = 2; sum < t; ++i){
      sum += 1.0/i;
    }
    printf("%d card(s)\n",i-2);
  }while(1);
}
