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

int Partition(int *array, const int left, const int right){
    cout<<"left:"<<left<<" right:"<<right<<endl;
    int pivot = array[right];
    int i = left;
    int j = 0;
    for( j = right - 1; j >= i;){
        if(array[i] <= pivot){
            ++i;
            continue;
        }
        if(array[j] >= pivot){
            --j;
            continue;
        }
        ExChange(array[i+1], array[j]);
        i++;
        j--;
    }
    ExChange(array[i], array[right]);
    return i;
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
    QuickSort(array,0,9);
    QuickSort(array2,0,9);
    for(int i = 0; i<10; ++i)
        cout<<array2[i]<<endl;
//    for(int i = 0; i<10; ++i)
//        cout<<array[i]<<endl;
    return 0;
}

