/*
 * =====================================================================================
 *
 *       Filename:    .\CHAPER02\2012_5_1_寻找最近点对\main.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012:5:1 13:38
 *       Compiler:    vc
 *       Description: 
 *              题目: 给定平面上N个点的坐标，找出距离最近的两个点
 *
 * =====================================================================================
 */
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
struct Point{
    double x;
    double y;
};
double dist_between_point(const Point& a, const Point& b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

struct Result{
    int i;
    int j;
    double min_dist;
};
// 方法1: 遍历O(n^2)的复杂度
Result min_difference_1(const Point arra[],int n){
    double min_dist = dist_between_point(arra[0],arra[1]);
    Result r;
    r.min_dist = dist_between_point(arra[0],arra[1]);
    r.i = 0;
    r.j = 1;
    for(int i = 0; i < n; ++i)
        for(int j = 1; j < n; ++j){
            if(i!=j){
                if(dist_between_point(arra[i],arra[j])<min_dist){
                    r.min_dist = dist_between_point(arra[i],arra[j]);
                    r.i = i;
                    r.j = j;
                }
            }
        }
    return r;
}


// 方法2: 通过分治的思想 时间复杂度减小到O(nlogn)
Result min_diff(const Point arr[],int n,int left,int right){
    Result r;
    r = min_diff(arr,n/2,left,left+n/2-1);

}
Result min_difference_2(const Point arra[],int n){
    Result r;


    return r;
}


int main(){
    ifstream f("input.dat"); 
    Point arr[10];
    for(int i=0; i<10; ++i){
        f>>arr[i].x>>arr[i].y;
    }
    Result r = min_difference_1(arr,10);
    cout<<"first point is:("<<arr[r.i].x<<","<<arr[r.i].y<<")"<<endl;
    cout<<"first point is:("<<arr[r.j].x<<","<<arr[r.j].y<<")"<<endl;
    cout<<"min dist is:"<<r.min_dist<<endl;


    int j = 10;
    int *p = NULL;
    //   const int *&q = p;

    return 0;
}

