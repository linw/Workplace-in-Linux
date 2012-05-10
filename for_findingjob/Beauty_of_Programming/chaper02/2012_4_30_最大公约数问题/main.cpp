/*
 * =====================================================================================
 *
 *       Filename:    .\CHAPER02\2012_4_30_最大公约数问题\main.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012:4:30 17:03
 *       Compiler:    vc
 *       Description: 
 *
 * =====================================================================================
 */
#include <iostream>
#include "time.h"
using namespace std;
// 方法1
unsigned long gcd_1(unsigned long a,unsigned long b){
    return (b!=0)?gcd_1(b,a%b):a;
}


// 方法2: 这种方法递归调用的层数有时会非常高
unsigned long gcd_2(unsigned long a, unsigned long b){
    if(a<b){
        return gcd_2(b,a);
    }
    if(b == 0)
        return a;
    return gcd_2(a-b,b);
}

// 方法3: 结合方法1和方法2,这种方法就是看两个数中有没有2的倍数，如果都有的话，公约数乘以这个倍数
bool is_even(unsigned long a){
    unsigned long t = 1;
    return a&t?false:true;
}

unsigned long gcd_3(unsigned long a, unsigned long b){
    if(a<b)
        return gcd_3(b,a);
    if(b==0)
        return a;
    if(is_even(a)){
        if(is_even(b))
            return (gcd_3(a>>1,b>>1)<<1);
        else 
            return gcd_3(a>>1,b);
    }
    else {
        if(is_even(b))
            return gcd_3(a,b>>1);
        else 
            return gcd_3(b,a-b);
    }
}


/*
 * =====================================================================================
 *
 *            以下是非递归版本
 *
 * =====================================================================================
 */
// 方法1的非递归版本
unsigned long _gcd_1(unsigned long a, unsigned long b){
    if(a<b){
        a^=b;
        b^=a;
        a^=b;
    }
    while(b>0){
        unsigned long tmp = b;
        b = a%b;
        a = tmp;
        if(a<b){
            a^=b;
            b^=a;
            a^=b;
        }
    }
    return a;
}

// 方法2的非递归版本
unsigned long _gcd_2(unsigned long a, unsigned long b){
    if(a<b){
        a^=b;
        b^=a;
        a^=b;
    }
    while(b>0){
        a = a-b;
        if(a<b){
            a^=b;
            b^=a;
            a^=b;
        }
    }
    return a;
}

// 方法3的非递归版本
unsigned long _gcd_3(unsigned long a, unsigned long b){
    if(a<b){
        a^=b;
        b^=a;
        a^=b;
    }
    unsigned long t = 1;
    while(b>0){
        if(is_even(a)){
            if(is_even(b)){
                t*=2;
                a=a>>1;
                b=b>>1;
            }
            else 
                a=a>>1;
        }
        else 
            a = a-b;
        if(a<b){
            a^=b;
            b^=a;
            a^=b;
        }
    }
    return a*t;
}


int main()
{
    time_t pre = clock();
    cout<<gcd_1(1,10100)<<endl;
    cout<<_gcd_1(1,10100)<<endl;
    cout<<gcd_2(200,10100)<<endl;
    cout<<_gcd_2(42,30)<<endl;
    cout<<gcd_3(1,10100)<<endl;
    cout<<_gcd_3(42,30)<<endl;
    time_t after = clock();
    cout<<(after-pre)/CLOCKS_PER_SEC<<endl;
    if(is_even(1235161))
        cout<<"hello"<<endl;
    return 0;
}