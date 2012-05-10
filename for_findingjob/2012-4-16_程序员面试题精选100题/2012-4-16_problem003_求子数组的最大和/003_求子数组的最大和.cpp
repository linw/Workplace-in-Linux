/*
 * =====================================================================================
 *
 *       Filename:    003_求子数组的最大和.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-5 11:28:54
 *       Compiler:    gcc
 *       Description: 
 *              题目：输入一个整形数组，数组里有正数也有负数。数组中连续的一个或多个整数组成一个子数组，每个
 *                   子数组都有一个和。求所有子数组的和的最大值。要求时间复杂度为O(n)。
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;
// 方法一：计算所有子串的值然后得出连续子数组的最大和。这是最简单的方法，时间复杂度为O(n^3)
int find_greatest_sum_1(const int* a, const int& n){
    int sum = INT_MIN;
    int tmp = 0;
    // cout<<sum<<endl;
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            tmp = 0;
            for(int k = j; k < n; ++k){
                tmp += a[k];
                if(tmp > sum)
                    sum = tmp;
            }
        }
    }
    return sum;
}


// 方法2: 可以对方法1进行简化。实际上不需要3重循环，只需要两重循环就可以，时间复杂度为O(n^2)。
int find_greatest_sum_2(const int* a, const int& n){
    int sum = INT_MIN;
    int tmp = 0;
    for(int i = 0; i < n; ++i){
        tmp = 0;
        for(int j = i; j < n; ++j){            
            tmp += a[j];
            if(tmp > sum)
            sum = tmp;
        }
    }
    return sum;    
}

// 方法3: 现在来实现一种更简洁的O(n)复杂度的算法. 利用动态规划算法
int find_greatest_sum_3(const int* a, const int& n){
    int sum = INT_MIN;
    int tmp = 0;
    int* all = new int[n];
    int* start = new int[n];
    for(int i = 0; i < n; ++i){
        all[i] = start[i] = 0;
    }
    all[n-1] = start[n-1] = a[n-1];
    for(int i = n-2; i >= 0; --i){
        start[i] = a[i]>(a[i]+start[i+1])? a[i]:a[i]+start[i+1];
        all[i] = start[i]>all[i+1]? start[i]:all[i+1];
    }
    sum = all[0];
    delete []all;
    delete []start; 
    return sum;
}

// 方法3: 利用动态规划的方法，时间复杂度为O(n)，但是空间复杂度也从O(1)变成了O(n)，其实空间复杂度也可以设计成O(1)，
//        上面程序中其实只用到了当前的start，all和 上一个的start，all。 所以通过设定4个变量就可以实现，空间复杂度
//        下降为O(1)
int find_greatest_sum_4(const int* a, const int& n){
    assert(a);
    assert(n <= 0);
    int all;
    int start;
    all= start = a[n-1];
    for(int i = n-2; i >= 0; --i){
        start = a[i]>(a[i]+start)? a[i]:(a[i]+start);
        all = start>all? start:all;
    }
    return all;
}

int main()
{
    // int a[8] = {1,-2,3,10,-4,7,2,-5};
    int a[8] = {-1,-2,-3,-10,-4,-7,-2,-5};
    int sum = 0;
    sum = find_greatest_sum_4(a,0);
    cout<< sum << endl;

    // int sum = 0;
    // FindGreatestSumOfSubArray(a,8,sum);
    // cout<<sum<<endl;
    return 0;
}
