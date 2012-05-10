/*
 * =====================================================================================
 *
 *       Filename:    .\2012_4_30_��ȷ��︡����\main.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012:4:30 12:25
 *       Compiler:    vc
 *       Description: 
 *               ��Ŀ:���÷�����ȷ��ʾѭ����������
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;
unsigned long Gcd(unsigned long a,unsigned long b);
struct Fraction{
    // ������ʾһ������
    unsigned long numerator; // ����
    unsigned long denominator; // ��ĸ
    bool sign;
};
struct Circulator{
    // ����ѭ��С�� 123.349683(4781)�������ڱ�ʾѭ������
    unsigned long unsigned_integer; //�������� 123
    unsigned long no_circul_decimals; // ��ѭ��С������ 349683
    unsigned long circul_decimals; // ѭ��С������ 4781
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

