/*
 * =====================================================================================
 *
 *       Filename:    2012_4_22_1�ĸ���\main.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     22:4:2012   20:05
 *       Compiler:    vc
 *       Description: 
 *                ��Ŀ��
 *                    1.����һ��ʮ������N��д�´�1��ʼ����N������������Ȼ����һ��
 *                      ���г��ֵ����С�1���ĸ�����
 *                    2.����������f(N)=N"������N�Ƕ��٣�
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

/*
 *                    1.����һ��ʮ������N��д�´�1��ʼ����N������������Ȼ����һ��
 *                      ���г��ֵ����С�1���ĸ�����
 */

// ����1����򵥵ķ�������ÿ�������м��㡣���ַ����ĸ��Ӷȸ�O(N*lgN)

long find_howmany1_1(const unsigned long n){
    unsigned long count = 0;
    for(unsigned long i = 1; i <= n; ++i){
        unsigned long tmp = i;
        while(tmp){
            if(tmp%10 == 1)
                ++count;
            tmp /=10;
        }
    }
    return count;
}

// ����2��һ�����ӵ�ķ����������㷨Ч�����,�������ӶȽ�����O(len(N))
long find_howmany1_2(const unsigned long n){
    unsigned long count = 0;
    unsigned long iFactor = 1;
    unsigned long iLowerNum = 0;
    unsigned long iCurrNum = 0;
    unsigned long iHigherNum = 0;
    while(n/iFactor != 0){
        iLowerNum = n - (n/iFactor)*iFactor;
        iCurrNum = (n/iFactor)%10;
        iHigherNum = n/(iFactor*10);
        switch(iCurrNum){
            case 0:
                count += iHigherNum*iFactor;
                break;
            case 1:
                count += iHigherNum*iFactor+iLowerNum+1;
                break;
            default:
                count += (iHigherNum + 1)*iFactor;
                break;
        }
        iFactor *= 10;
    }
    return count;
}

/*
 *                    2.����������f(N)=N"������N�Ƕ��٣�
 */
unsigned long find_max_N(){
    unsigned long max_n = 0;
    for(unsigned long i = 9999999999;i>0;--i){
        if(find_howmany1_2(i) == i){
            max_n = i;
            break;
        }
    }
    return max_n;
}


/*
 *====================================================================================
 *
 *                  �����������
 *
 *
 *====================================================================================
 */
unsigned long bi_find_howmany1_1(const unsigned long n){
    unsigned long count = 0;
    for(int i = 0; i<=n; ++i){
        unsigned long tmp = i;
        while(tmp){
            tmp&=(tmp-1);
            count++;
        }
    }
    return count;
}

unsigned long bi_find_howmany1_2(const unsigned long n){
    unsigned long count = 0;

    return count;
}



int main(int argc, char **argv){
/*    cout<<find_howmany1_2(100)<<endl;*/
//    cout<<find_max_N()<<endl;
    cout<<bi_find_howmany1_1(3)<<endl;

    return 0;
}