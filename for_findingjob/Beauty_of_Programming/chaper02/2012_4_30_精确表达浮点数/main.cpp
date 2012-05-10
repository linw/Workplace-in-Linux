/*
 * =====================================================================================
 *
 *       Filename:    .\2012_4_30_精确表达浮点数\main.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012:4:30 12:25
 *       Compiler:    vc
 *       Description: 
 *               题目:利用分数精确表示循环浮点数。
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;
unsigned long Gcd(unsigned long a,unsigned long b);
struct Fraction{
    // 用来表示一个分数
    unsigned long numerator; // 分子
    unsigned long denominator; // 分母
    bool sign;
};
struct Circulator{
    // 例如循环小数 123.349683(4781)。括号内表示循环部分
    unsigned long unsigned_integer; //整数部分 123
    unsigned long no_circul_decimals; // 非循环小数部分 349683
    unsigned long circul_decimals; // 循环小数部分 4781
    bool sign;
};
Fraction transfor_circulator_to_fraction(const Circulator& cn){
    unsigned long no_circul_m = 1;
    unsigned long circul_m = 1;
    Fraction f;
    while(cn.no_circul_decimals/no_circul_m)
        no_circul_m *= 10;
    while (cn.circul_decimals/circul_m)
        circul_m *= 10;
    f.numerator = (cn.unsigned_integer*no_circul_m+cn.no_circul_decimals)*(circul_m-1)+cn.circul_decimals;
    f.denominator = no_circul_m * (circul_m - 1);
    f.sign = cn.sign;
    return f;
}

Fraction simplify_fraction(const Fraction& f){
    Fraction simplify_f;
    unsigned long t = Gcd(f.denominator,f.numerator);
    simplify_f.denominator = f.denominator/t;
    simplify_f.numerator = f.numerator/t;
    simplify_f.sign = f.sign;
    return simplify_f;

}


unsigned long Gcd(unsigned long a,unsigned long b){
    if(a<b){
        b=b+a;
        a=b-a;
        b=b-a; 
    }
    unsigned long k=a,m=b;
    while(m>0){
        unsigned long tmp1 = k,tmp2 = m;
        k = tmp2;
        m = tmp1%tmp2;
        if(k<m){
            k^=m;
            m^=k;
            k^=m;
        }
    }
    return k;
}

int main()
{
    Circulator cn;
    cn.unsigned_integer = 0;
    cn.no_circul_decimals = 0;
    cn.circul_decimals = 33;
    cn.sign = true;
    Fraction f;
    f = transfor_circulator_to_fraction(cn);
    f = simplify_fraction(f);
    printf("Circulator is:%d.%d(%d)\n",cn.unsigned_integer,cn.no_circul_decimals,cn.circul_decimals);
    printf("Fraction : %d\/%d\n",f.numerator,f.denominator);
    return 0;
}

