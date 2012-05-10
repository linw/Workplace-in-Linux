/*
 * =====================================================================================
 *
 *       Filename:    .\CHAPER02\2012_5_2_����Ѱ������������������\main.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012:5:2 20:38
 *       Compiler:    vc
 *       Description: 
 *              ��Ŀ: ����һ������a[N]��һ����sum���ܷ��ҵ��������ĺ͵���sum
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;
// ����1: ��򵥷������������еĺ�
int find_1(const int arr[], const size_t n, const int sum){
    int flag = -1;
    for(int i = 0; i < n; ++i)
        for(int j = i+1; j < n; ++j){
            if(arr[i]+arr[j]==sum&&i!=j){
                cout<<arr[i]<<" + "<<arr[j]<<" = "<<sum<<endl;
                flag = 1;
            }
        }
    return flag;
}

// ����2: ���ò��ҵ�˼·������sum-arr[i]

size_t BinarySearch(const int arr[], const size_t n, const int s){ // �۰����
    size_t l = 0;
    size_t r = n-1;
    size_t mid = (r+l)/2;
    bool flag = false;
    while(l<r-1){
        if(arr[mid] == s) { flag = true;break;}
        else if(s<arr[mid]){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
        mid = (r+l)/2;
    }
    return flag?mid:-1;
}
int find_2(const int arr[], const size_t n, const int sum){
    int flag = -1;
    int lf;
    for(int i = 0; i < n; ++i){
        lf = sum - arr[i];
        int j = BinarySearch(arr,n,lf);
        if(j!=-1&&i!=j)
            cout<<arr[i]<<" + "<<arr[j]<<" = "<<sum<<endl;
    }
    return 0;
}


int main(int argc, char **argv)
{
    int arr[10] = {1,2,4,23,7,2,4,0,3,9};
    int arr1[10] = {1,2,3,4,5,5,7,8,9,10};
//    find_1(arr,10,5);
    size_t i = BinarySearch(arr1,10,4);
    find_2(arr1,10,5);

    cout<<i<<endl<<arr1[i]<<endl;
//    cout<<arr1[i]<<endl;
    return 0;
}
