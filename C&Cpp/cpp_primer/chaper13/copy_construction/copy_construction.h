/*
 * =====================================================================================
 *
 *       Filename:    copy_construction.h
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年3月19日22:11:42
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#ifndef _COPY_CONSTRUCTION_H
#define _COPY_CONSTRUCTION_H
#include <iostream>
using namespace std;
class copy_construction
{
public:
    copy_construction(){cout<<"defaut construction"<<endl;};
    copy_construction(const copy_construction& _c){cout<<"use copy"<<endl;};
    virtual ~copy_construction(){};
};

#endif
