/*
 * FileName: QuickSort.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-14
 * Description: Quick sort algorithms.
 */
#include <iostream>
#include <list>
using namespace std;
// Swap two value.
void ExChange(int &a, int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}

int Partition(int array[], const int left, const int right){
    int tmp = array[right];
    int l = left-1;
    int r = left;
    while(r<right){
        if(tmp>array[r]){
            if(l+1!=r)
                ExChange(array[l+1],array[r]);
            ++l;            
        }
        ++r;
    } 
    if(l+1!=r)
        ExChange(array[l+1],array[right]);
    return l+1;
}

void QuickSort(int *array, const int n){
    if(n>0)
    {
        int i = Partition(array,0,n-1);
//        cout<<"int i = Partition(array,left,right)"<<i<<endl;
        QuickSort(array,i);
        QuickSort(array+i+1,n-1-i);
    }
}

int main()
{
    int array[10] = {0,1,2,3,4,5,6,7,8,9};
    int array1[10] = {9,8,7,6,5,4,3,2,1,0};
    int array2[10] = {6,8,2,9,5,0,3,7,1,4};
    QuickSort(array1,10);
    QuickSort(array2,10);
    Partition(array2,0,9);
    for(int i = 0; i<10; ++i)
        cout<<array1[i]<<endl;
//    for(int i = 0; i<10; ++i)
//        cout<<array[i]<<endl;
    return 0;
}

