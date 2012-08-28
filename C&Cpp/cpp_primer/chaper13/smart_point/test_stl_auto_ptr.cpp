/*
 * =====================================================================================
 *
 *       Filename:    test_stl_auto_ptr.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-5 22:01:46
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include <memory>
#include <string>
#include <iostream>
using namespace  std;
int main(int argc, char const *argv[])
{
    /* code */
    auto_ptr<int> pstr (new int);
    *pstr.get() = 42;
    cout<<*pstr.get()<<endl;
    return 0;
}

