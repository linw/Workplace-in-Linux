/*
 * FileName: InsertionSort.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-8
 * Description: Insert sort algorithms.
 *
 */
#include <iostream>
using namespace std;
void InsertionSortUp(int *source, size_t length){
    int tmp = 0;
    int j = 0;
    for(size_t i = 1; i != length; ++i){
        tmp = source[i];
        j = i - 1;
        while(j >= 0 && tmp < source[j]){
            source[j+1] = source[j];
            --j;
        }
        source[j+1] = tmp;
    }
}

void InsertionSortDown(int *source, size_t length){
    int tmp = 0;
    int j = 0;
    for(size_t i = 1; i != length; ++i){
        tmp = source[i];
        j = i - 1;
        while(j >= 0 && tmp > source[j]){
            source[j+1] = source[j];
            --j;
        }
        source[j+1] = tmp;
    }
}
int main(){

    cout<<"Hello World!"<<endl;
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    InsertionSortUp(a, 10);
    
    for(size_t i = 0; i < 10; ++i)
        cout<<a[i]<<endl;
    InsertionSortDown(a, 10);
    a[0] = 31;
    a[1] = 41;
    a[2] = 59;
    a[3] = 26;
    a[4] = 41;
    a[5] = 58;
    
    InsertionSortDown(a, 10);
    for(size_t i = 0; i < 10; ++i)
        cout<<a[i]<<endl;
    return 0;
}

