/*
 * =====================================================================================
 *
 *       Filename:    .\CHAPER02\2012_4_30_斐波那契数列\main.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012:4:30 21:07
 *       Compiler:    vc
 *       Description: 
 *
 * =====================================================================================
 */
#include <iostream>
#include "time.h"
#include "math.h"
using namespace std;
// 方法1: 通过递归方法，效率较低
unsigned long fibonacci_1(unsigned long n){
    if(n<=0)
        return 0;
    if(n==1)
        return 1;
    else 
        return fibonacci_1(n-1)+fibonacci_1(n-2);
}
// 方法2: 通过地推公式计算，效率提高，没有了递归中的递归调用，时间复杂度为O(n)
unsigned long fibonacci_2(unsigned long n){
    unsigned long sum0 = 0;
    unsigned long sum1 = 1;
    if(n<=0)
        return 0;
    else if(n==1)
        return 1;
    else {
        for(int i = 1; i<n; ++i){
            unsigned long tmp = sum1;
            sum1 = sum0+sum1;
            sum0 = tmp;
        }
    }
    return sum1;
}
// 方法3: 通过求解通项公式来计算，这种方法出现了无理数，所以结果不精确
unsigned long fibonacci_3(unsigned long n){
    double sqrt_5 = sqrt(5);
    double result = sqrt_5*(pow(1+sqrt_5,n)-pow(1-sqrt_5,n))/(5*pow(2,n));
    return result;
}

#ifdef FIBONACCI_4
// 方法4: 分治策略
// (Fn Fn-1) = (Fn-1 Fn-2)*A
template<typename T>
class Matrix{
public:
    Matrix(size_t _m=1,size_t _n=1){
        m = _m;
        n = _n;
        matrix = new T*[m];
        for(int i = 0; i<m;++i)
            matrix[i] = new T[n];

    }
    virtual ~Matrix(){
        for(int i = 0; i<m;++i)
            delete[] matrix[i];
        delete[] matrix;
    };
public:
    void zero_matrix(){
        for(int j=0;j<m;++j)
            for(int k=0;k<n;++k)
                matrix[j][k] = 0;
    }
    void identity_matrix(){
        zero_matrix();
        for(int j=0;j<m;++j)
            for(int k=0;k<n;++k)
                if(j == k)
                    matrix[j][k] = 1;
    }
    void self_mulit(){

    }


private:
    T** matrix; 
    size_t m;
    size_t n;
};
unsigned long fibonacci_4(unsigned long n){

}
#endif


int main()
{
    time_t pre;
    time_t after;
    pre = clock();
//     cout<<fibonacci_1(10)<<endl;
//     cout<<fibonacci_2(100)<<endl;
    cout<<fibonacci_3(10)<<endl;
    after = clock();
    cout<<(after-pre)/CLOCKS_PER_SEC<<endl;
    return 0;
}