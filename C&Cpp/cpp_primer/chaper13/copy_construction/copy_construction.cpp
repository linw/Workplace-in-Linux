/*
 * =====================================================================================
 *
 *       Filename:    copy_construction.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年3月19日22:11:42
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include "copy_construction.h"
#include <iostream>
using namespace std;
void fun(copy_construction a){

};
int main()
{
    copy_construction a;
    copy_construction b;
    a = copy_construction(b);
    fun(a);
    return 0;
}
