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
    int l = left;
    int r = right-1;
    while(l<=r){
        if(array[l]>tmp){
            if(l!=r)
                ExChange(array[l],array[r]);
            --r;
        }
        else if(array[r]<tmp){
            if(l!=r)
                ExChange(array[l],array[r]);
            ++l;
        }
        else{
            ++l;
            --r;
        }
    }
    if(l!=r){
        array[right] = array[l];
        array[l] = tmp;
        return l;
    }
    else {
        ExChange(array[r],array[right]);
        return r;
    }
}

void QuickSort(int *array, const int left, const int right){
    if(left < right)
    {
        int i = Partition(array,left,right);
//        cout<<"int i = Partition(array,left,right)"<<i<<endl;
        QuickSort(array,left,i-1);
        QuickSort(array,i+1,right);
    }
}

int main()
{
    int array[10] = {0,1,2,3,4,5,6,7,8,9};
    int array1[10] = {9,8,7,6,5,4,3,2,1,0};
    int array2[10] = {6,8,2,9,5,0,3,7,1,4};
    QuickSort(array1,0,9);
    QuickSort(array2,0,9);
    for(int i = 0; i<10; ++i)
        cout<<array1[i]<<endl;
//    for(int i = 0; i<10; ++i)
//        cout<<array[i]<<endl;
    return 0;
}

