/*
 * =====================================================================================
 *
 *       Filename:    smart_point.h
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年3月21日22:15:02
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#ifndef  _CHAPER13_SMART_POINT_H
#define _CHAPER13_SMART_POINT_H
#include <iostream>
using namespace std;
class Smart_Ptr
{
    friend class Has_smart_point;
    int *ip;
    size_t use;
    Smart_Ptr(int *ip): ip(ip), use(1){}
    virtual ~Smart_Ptr(){ delete ip;}
};
#endif
