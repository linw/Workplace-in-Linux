/*
 * =====================================================================================
 *
 *       Filename:    2012_4_22_不要被阶乘吓倒\main.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     22:4:2012   20:05
 *       Compiler:    vc
 *       Description: 
 *               1.题目：给定一个整数N，那么N的阶乘N!末尾有多少个0呢?例如：N=10，N!=3628800
 *                     N!的末尾有两个0
 *               2.题目：求N!的二进制表示中最低位1的位置。
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;


/*
 * =====================================================================================
 *           1.题目：给定一个整数N，那么N的阶乘N!末尾有多少个0呢?例如：N=10，N!=3628800
 *                     N!的末尾有两个0           
 * =====================================================================================
 */


// 方法1：通过对N中2和5的个数进行统计从而计算出末尾0的个数
size_t howmany_end_zero_1(int n){
    int count_5 = 0;
    int count_2 = 0;
    int i,j;
    for(i = 1; i <= n; ++i){
        j = i;
        while(j>=5){
            if(j%5 == 0)
                ++count_5;
            else break;
            j /= 5;
        }
    }
    //而出现的频率比5高出好多，所以这里可以忽略2
//     for(i = 1; i <= n; ++i){
//         j = i;
//         while(j>=2){
//             if(j%2 == 0)
//                 ++count_2;
//             else break;
//             j /= 2;
//         }
//     }
    return count_5;
}

// 方法2: 这种方法就是统计所有5的倍数贡献的5的个数，让后加在一起就可以计算出总共5的个数
size_t howmany_end_zero_2(int n){
    int count = 0;
    while(n){
        count += n/5;
        n /= 5;
    }
    return count;
}



/*
 * =====================================================================================                        
 *            2.题目：求N!的二进制表示中最低位1的位置。       
 * =====================================================================================
 */

// 方法1:
unsigned int first_end_pos_one_1(int n){
    int count = 0;
    // 这里计算出了末尾0的个数
    for(int i = 1; i <= n; ++i){
        int j = i;
        while(j){
            if(j%2 == 0)
                ++count;
            else break;
            j /= 2;
        }
    }
    return count+1; // 需要加1才能得到1的位置
}

// 方法2:
unsigned int first_end_pos_one_2(int n){
    int count = 0;
    while(n){
        count += n/2;
        n /= 2;
    }
    return count+1;

}






int main(int argc, char **argv)
{
    cout<<howmany_end_zero_2(100)<<endl;
    cout<<first_end_pos_one_2(10000)<<endl;
    return 0;
}

