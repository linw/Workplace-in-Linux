/*
 * =====================================================================================
 *
 *       Filename:    005_查找最小的k个元素.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-18 20:06:20
 *       Compiler:    gcc
 *       Description: 
 *              题目：输入n个整数，输出其中最小的k个。
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;
// 方法1: 给出最简单的方法，O(n*k)的复杂度
void find_kmin_1(const int* a, int* kmin, int n, int k){
    int i = 0;
    int max = INT_MIN;
    int max_i = 0;
    for(i = 0; i < k; ++i){
        kmin[i] = a[i];
        if(max<kmin[i]){
            max = kmin[i];
            max_i = i;
        }
    }
    for(i = k; i < n; ++i){
        // if(max<=a[i]) continue;
        max = INT_MIN;
        int j;
        for(j = 0; j < k; ++j){
            if(max<kmin[j]){
                max = kmin[j];
                max_i = j;
            }
        }
        if(max<=a[i]) continue;
        else kmin[max_i] = a[i];
    }
}

// 方法2::利用大顶堆的概念
void max_heap(int* maxHeap, int n, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = 0;
    if(l <= n && maxHeap[l]>maxHeap[i])
        largest = l;
    else largest = i;
    if(r<=n && maxHeap[r]>maxHeap[largest])
        largest = r;
    if(largest != i){
        maxHeap[i] = maxHeap[i]^maxHeap[largest];
        maxHeap[largest] = maxHeap[i]^maxHeap[largest];
        maxHeap[i] = maxHeap[i]^maxHeap[largest];
        max_heap(maxHeap,n,largest);
    }
}
void find_kmin_2(const int* a, int* kmin, int n, int k){
    for(int i = 0; i < k; ++i)
        kmin[i] = INT_MAX;
    for(int i = 0; i < n; ++i){
        if(a[i] < kmin[0]){
            kmin[0] = a[i];
            max_heap(kmin,k,0);
        }
    }
}


// 方法3: pdf 中的方法

typedef multiset<int, greater<int> > IntHeap;
/////////////////////////////////////////////////////////////////////
//find k least numbers in a vector
/////////////////////////////////////////////////////////////////////
//
void FindKLeastNumbers
(
    const vector<int>& data, // a vector of data
    IntHeap& leastNumbers, // k least numbers, output
    unsigned int k
)
{
    leastNumbers.clear();
    if(k == 0 || data.size() < k)
        return;
    vector<int>::const_iterator iter = data.begin();
    for(; iter != data.end(); ++ iter)
    {
        // if less than k numbers was inserted into leastNumbers
        if((leastNumbers.size()) < k)
            leastNumbers.insert(*iter);
        // leastNumbers contains k numbers and it's full now
        else
        {
        // first number in leastNumbers is the greatest one
            IntHeap::iterator iterFirst = leastNumbers.begin();
            // if is less than the previous greatest number
            if(*iter < *(leastNumbers.begin()))
            {
            // replace the previous greatest number
                leastNumbers.erase(iterFirst);
                leastNumbers.insert(*iter);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int a[10] = {1,0,0,3,5,4,0,9,2,6};
    int kmin[5];
    std::vector<int> v(a);
    IntHeap ih;
    // find_kmin_3(a,kmin,10,5);
    FindKLeastNumbers(v,ih,5);
    for(int i = 0; i < 5; ++i)
        cout<<kmin[i]<<endl;
    return 0;
}
