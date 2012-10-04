// #include <iostream>
// using namespace std;

// int main()
// {
//   int i;
//   double sum;
//   double tmp;
//   sum = 0;
//   for(i = 0; i < 12; ++i){
//     cin>>tmp;
//     sum += tmp;
//   }
//   cout<<'$'<<sum/12<<endl;
//   return 0;
// }
#include <stdio.h>
main()
{
  int i;
  double tmp;
  double sum;
  sum = 0;
  for(i = 0; i < 12; ++i){
    scanf("%lf",&tmp);
    sum += tmp;
  }
  printf("$%lf\n",sum/12);
}
