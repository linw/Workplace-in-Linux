/*
 * =====================================================================================
 *
 *       Filename:    main.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-20 15:25:04
 *       Compiler:    vc6.0
 *       Description: 找到一个数的二进制表示中1的个数。
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;
int find_nums_1(unsigned int i){
    int sum = 0;
    while(i){
        if(i%2 == 0)
            sum++;
        i /= 2;
    }
    return sum;
}

int find_nums_2(unsigned int i){
    int sum = 0;
    while(i){
        sum += i &0x01;
        i>>=1;
    }
    return sum;
}

int find_nums_3(unsigned int i){
    int sum = 0;
    while(i){
        i &=(i-1);
        ++sum;
    }
    return sum;
}


// 一个计算末尾0个数的算法，超级牛逼
// 来源http://www.matrix67.com/blog/archives/3985
int find_nums_4(unsigned int i){
    static const int MultiplyDeBruijnBitPosition[32] =
    {
        0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
            31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9
    };
    return MultiplyDeBruijnBitPosition[((unsigned int)((i & -i) * 0x077CB531U)) >> 27];
}

int main(int argc, char **argv)
{
    cout<<find_nums_4(10)<<endl;
    for(unsigned int i = 0; i < 255; ++i){
        if(i%15 == 0) cout<<endl;
        cout<<find_nums_4(i)<<" ";
        
    }
    cout<<endl;
    return 0;
}