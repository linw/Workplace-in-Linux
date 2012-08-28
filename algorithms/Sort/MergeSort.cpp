/*
 * FileName: MergeSort.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-13
 * Description: Merge sort algorithms.
 *
 */
#include <iostream>
#include "limits.h"
using namespace std;
//array[p,q] and array[q+1,r] already sorted, so merge
//them to sorted array[p,r] will cost litte.O(n)
void Merge(int *array, size_t p, size_t q, size_t r){
   size_t i = 0;
   size_t j = 0;
   size_t n1 = q - p + 1;
   size_t n2 = r - q;
   int *L = new int[n1+1];
   int *R = new int[n2+1];
   for(i = 0; i != n1; ++i)
       L[i] = array[p+i];
   for(i = 0; i != n2; ++i)
       R[i] = array[q+1+i];
   L[n1] = R[n2] = INT_MAX;
   i = j = 0;
   for(int k = p; k != r + 1; ++k){
       if(L[i] <= R[j]){
           array[k] = L[i];
           i++;
       }
       else{
           array[k] = R[j];
           j++;
       }
   }
   delete []L;
   delete []R;
}
void MergeSort(int *array, size_t p, size_t r){
    if(p < r){
        size_t q = (p+r)/2;
        MergeSort(array, p, q);
        MergeSort(array, q+1, r);
        Merge(array, p, q, r);
    }
}
int main()
{
    int a[8] = {3,41,52,26,38,57,9,49};
    MergeSort(a,0,7);
    for(int i = 0; i != 8; ++i)
        cout<<a[i]<<endl;
    return 0;
}
