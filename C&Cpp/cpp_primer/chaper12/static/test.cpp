/*
 * =====================================================================================
 *
 *       Filename:    test.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年3月18日21:28:26
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */

 #include <iostream>
 using namespace std;
 int main()
 {
    const int i = 10;
    int *p = (int*)&i;
    int k = 10;
    cout<<i<<" "<<*p<<endl;
    (*p) ++;
    cout<<i<<" "<<*p<<endl;
    cout<<hex<<p<<endl;
    cout<<&k<<endl;
    return 0;
 }
