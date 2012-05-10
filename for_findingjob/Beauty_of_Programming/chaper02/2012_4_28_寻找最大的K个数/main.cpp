/*
 * =====================================================================================
 *
 *       Filename:    .\CHAPER02\2012_4_28_寻找最大的K个数\main.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012:4:28 18:03
 *       Compiler:    vc
 *       Description: 
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;
#define MIN_HEAP

// #ifdef MAX_HEAP     // 从一个无须数组建立大顶堆的过程
// 
// void max_heapify(int a[],int ii,int n){
//     size_t largest = ii;
//     if((2*ii+1)<n&&a[largest]<a[2*ii+1])
//         largest = 2*ii+1;
//     if((2*ii+2)<n&&a[largest]<a[2*ii+2])
//         largest = 2*ii+2;
//     if(ii!=largest){
//         a[ii] = a[ii]^a[largest];
//         a[largest] = a[ii]^a[largest];
//         a[ii] = a[ii]^a[largest];
//         max_heapify(a,largest,n);
//     }
// }
// 
// void build_max_heap(int a[], int n){
//     for(int i = n/2;i>=0;--i)
//         max_heapify(a,i,n);
// }
// #endif  //end  从一个无须数组建立大顶堆的过程




// 方法1：利用小顶堆
#ifdef MIN_HEAP // 从一个无须数组建立小顶堆的过程
void min_heapify(int a[],int ii,int n){
    size_t minest = ii;
    if((ii*2+1)<n&&a[minest]>a[ii*2+1])
        minest = ii*2+1;
    if((ii*2+2)<n&&a[minest]>a[ii*2+2])
        minest = ii*2+2;
    if(minest!=ii){
        a[minest] ^= a[ii];
        a[ii] ^= a[minest];
        a[minest] ^= a[ii];
        min_heapify(a,minest,n);
    }
}

void build_min_heap(int a[], int n){
    for(int i = n/2; i>=0;--i){
        min_heapify(a,i,n);
    }
}
#endif //end  从一个无须数组建立小顶堆的过程

void find_max_k(int a[],int n,int max_k[],int k){
    for(int i = 0; i < n; ++i){
        if(i<k){
            max_k[i] = a[i];
            min_heapify(max_k,0,i);
        }
        else{
            if(a[i]>max_k[0]){
                max_k[0] = a[i];
                min_heapify(max_k,0,k);
            }
        }
    }
}




// 方法2: 利用快排的划分思想
void ExChange(int &a, int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}
size_t partition(int a[],size_t left,size_t right){
    int tmp = a[right];
    int i = left-1;
    int j = left;
    while(j!=right-1){
        if(a[j]<=tmp){
            i++;
            ExChange(a[i],a[j]);
        }
        j++;
    }
    ExChange(a[i+1],a[right]);
    return i+1;
}

void find_max_k_1(int a[],int n,int max_k[],int k){
//     int i = 0;
//     i = partition(a,0,n-1);
//     if(k==0) return;
//     if()
}


/// 方法3：利用计数的方法
#define MAXN 100
void find_max_k_2(int a[],int n,int max_k[],int k){
    size_t count_n[MAXN];
    int i = 0;
    for(i = 0; i < MAXN; ++i){
        count_n[i] = 0;
    }
    for(i = 0; i < n; ++i){
        ++count_n[a[i]];
    }
    int i_k = 0;
    for(i = MAXN-1; i >=0 &&i_k<k; --i){
        if(count_n[i]!=0){
            for(int j = 0; j<count_n[i]&&i_k<k;++i_k,++j){
                max_k[i_k] = i;
            }
        }
    }
}


int main(int argc, char **argv)
{
/*    int a[6] = {1,4,6,2,9,3};*/
    int a[10] = {1,5,7,6,5,9,2,1,10,32};
    int max_k[5];
/*    partition(a,0,5);*/
    /*    build_max_heap(a,10);*/
    /*    max_heap(a,3,10);*/
    /*    build_min_heap(a,10);*/
    find_max_k_2(a,10,max_k,5);
//     for(int j = 0; j < 6; ++j)
//         cout<<a[j]<<endl;
    for(int i = 0; i < 5; ++i){
        cout<<max_k[i]<<endl;
    }
//     int i =0;
//     int j = 1;
//     i = i^i;
//     i = i^i;
//     i = i^i;
//     cout<<i<<endl;
/*   cout<<a[0]<<endl;*/
    return 0;
}
