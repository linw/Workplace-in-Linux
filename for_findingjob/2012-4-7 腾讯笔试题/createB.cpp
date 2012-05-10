/*
 * =====================================================================================
 *
 *       Filename:    createB.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-9 17:11:33
 *       Compiler:    gcc
 *       Description: 腾讯笔试附加题：
 *            题目：已知一个数组a[N]，构造一个数组b[N]，
 *                  构造规则：b[i]=a[0]*a[1]*a[2]...a[N]/a[i];
 *　          要求：
 *　　　　　          1、不可以使用除法；
 *　　　　            2、时间复杂度为O(n)，空间复杂度为S(1)；
 *　　　　            3、除遍历使用的变量外，不可以使用其它变量；
 *            解题思路：
 *                   该题目的形式像一个矩阵，然后通过重复利用b[n]和
 *              a[n] 来存储上下三角的乘积，然后综合得出结果。
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;
void createB(long a[], long b[], size_t n){
    int i = 0;
    b[i] = 1;
    for(i = 1; i < n; ++i){
        b[i] = a[i-1]*b[i-1];
    }
    long k = a[n];
    a[n] = 1;
    for(i = n-1; i >= 0; --i){
        a[i] = a[i+1] * a[i];
    }
    for(i = 0; i< n-1; ++i){
        b[i] = a[i+1]*b[i];
    }
}

int main(){
    long a[6] = {2,1,2,3,4,5};
    long b[6];
    createB(a,b,6);
    for(int i = 0; i < 6; ++i)
        cout<<b[i]<<endl;
    return 0;
}
