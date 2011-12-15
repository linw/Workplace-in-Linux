/*
 * FileName: BubbleSort.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-13
 * Description: Bubble sort algorithms.
 *
 */
#include <iostream>
#include "limits.h"
using namespace std;
void BubbleSort(int *array, size_t length){
   size_t i = 0;
   size_t j = 0;
   for(i = 0; i < length; ++i){
      for(j = length - 1; j > i; --j){
          if(array[j-1] > array[j]){
              array[j-1] = array[j-1]^array[j];
              array[j] = array[j-1]^array[j];
              array[j-1] = array[j-1]^array[j];
          }
      } 
}
}
int main()
{
    int a[8] = {8,7,6,5,4,3,2,1};
    BubbleSort(a, 8);
    for(size_t i = 0; i < 8; ++i)
        cout<<a[i]<<endl;
    return 0;
}

