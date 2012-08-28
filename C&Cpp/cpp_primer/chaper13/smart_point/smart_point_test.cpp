/*
 * =====================================================================================
 *
 *       Filename:    smart_point_test.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年3月21日23:03:20
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include <iostream>
#include "smart_point_test_class.h"
using namespace std;
void fun(int *&p){
    Has_smart_point c(p);
    cout<<c.get_use_status()<<endl;
}
int main()
{
    int *p = new int;
    int *p1 = new int;
    *p1 = 20;
    *p = 10;
    Has_smart_point a(p);
    cout<<a.get_use_status()<<endl;
    Has_smart_point b(a);
    cout<<a.get_use_status()<<endl;
    cout<<b.get_use_status()<<endl;
    fun(p);
    cout<<a.get_use_status()<<endl;

    return 0;
}
