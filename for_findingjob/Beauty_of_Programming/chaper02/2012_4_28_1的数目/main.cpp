/*
 * =====================================================================================
 *
 *       Filename:    2012_4_22_1的个数\main.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     22:4:2012   20:05
 *       Compiler:    vc
 *       Description: 
 *                题目：
 *                    1.给定一个十进制数N，写下从1开始，到N的所有整数，然后数一下
 *                      其中出现的所有“1”的个数。
 *                    2.满足条件“f(N)=N"的最大的N是多少？
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

/*
 *                    1.给定一个十进制数N，写下从1开始，到N的所有整数，然后数一下
 *                      其中出现的所有“1”的个数。
 */

// 方法1：最简单的方法，对每个数进行计算。这种方法的复杂度高O(N*lgN)

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

// 方法2：一个复杂点的方法，但是算法效率提高,这样复杂度降到了O(len(N))
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
 *                    2.满足条件“f(N)=N"的最大的N是多少？
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
 *                  处理二进制数
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