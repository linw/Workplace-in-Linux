/*
 * =====================================================================================
 *
 *       Filename:    test.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年3月19日21:22:32
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
using namespace std;
struct Dat
{
    int a;
    int b;
    double c;
};
int main()
{
    Dat a={1,1,1.0};
    cout<<a.a<<" "<<a.b<<" "<<a.c<<endl;
    return 0;
}
