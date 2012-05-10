/*
 * =====================================================================================
 *
 *       Filename:    .\CHAPER02\2012_5_1_Ѱ�������е����ֵ����Сֵ\main.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012:5:1 11:44
 *       Compiler:    vc
 *       Description: 
 *                ��Ŀ:Ѱ�������е����ֵ����Сֵ
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

struct Result{
    long min;
    long max;
};

// ����1: �����������飬�ܵıȽϴ���Ϊ2*N

Result find_1(int a[],size_t n){
    Result r;
    r.min = INT_MAX;
    r.max = INT_MIN;
    size_t count = 0;
    for(int i = 0; i < n; ++i){
        
        if(r.min>=a[i]){
            r.min = a[i];
            ++count;
        }
        else ++count;
        if(r.max<=a[i]){
            r.max = a[i];
            ++count;}
        else ++count;
    }
    if(r.max == INT_MIN) r.max = r.min,++count;
    cout<<"times:"<<count<<endl;
    return r;
}
// ����2: ��������ż��λ��Ȼ����������Сֵ
Result find_2(int a[],size_t n){
    Result r;
    int i = 0;
    size_t count = 0;
    r.min = INT_MAX;
    r.max = INT_MIN;
    for(i = 1; i < n; i+=2){
        if(a[i-1]>a[i]){
            a[i-1] = a[i-1] + a[i];
            a[i] = a[i-1] - a[i];
            a[i-1] = a[i-1] - a[i];
        }
        ++count;
    }
    for(i=0;i<n;i+=2){
        if(r.min>=a[i])
            r.min = a[i];
        ++count;
    }
    for(i=1;i<n;i+=2){
        if(r.max<=a[i])
            r.max = a[i];
        ++count;
    }
    cout<<"times:"<<count<<endl;
    return r;
}

int main()
{
    int a[10] = {1,5,3,9,45,0,-54,1,100,3};
//    int a[10] = {1,1,1,1,1,1,1,1,1,1};
    Result r = find_1(a,10);
//    Result r = find_2(a,10);
    cout<<"Max in a[]: "<<r.max<<endl;
    cout<<"Min in a[]: "<<r.min<<endl;
    return 0;
}