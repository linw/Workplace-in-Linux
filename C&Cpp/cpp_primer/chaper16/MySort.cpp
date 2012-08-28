/*
 * =====================================================================================
 *
 *       Filename:    MySort.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-19 15:53:30
 *       Compiler:    gcc
 *       Description: First test in new chaper, this chaper is mainly about template.
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
using namespace std;

int MyCompare(const double& v1, const double& v2){
    double res = v1 - v2;
    if(v1>v2) return 1;
    if(v1<v2) return -1;
    return 0;
}

template <typename T>
void sort(T* source, int size, int (*compare)(const T&, const T&)){
    assert(source);
    for(int i = 0; i < size; ++i){
        for(int j = i; j < size; ++j){
            if(compare(source[i],source[j])>0){
                T tmp;
                tmp = source[j];
                source[j] = source[i];
                source[i] = tmp; 
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    double a[10] = {1.1,5.6,4,8,3,0,5,4,10,2};
    sort(a,10,MyCompare);
    for(int i = 0; i < 10; ++i){
        cout<<a[i]<<endl;
    }
    // cout<<1.213-1.213<<endl;
    return 0;
}
