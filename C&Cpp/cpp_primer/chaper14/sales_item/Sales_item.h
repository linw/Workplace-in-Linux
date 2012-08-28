/*
 * =====================================================================================
 *
 *       Filename:    Sales_item.h
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-3-26 22:08:15
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#ifndef _CHAPER14_SALES_ITEM_H
#define _CHAPER14_SALES_ITEM_H
// #include <iostream>
// using namespace std;

class Sales_item
{
private:
    int i;
    double f;
public:
    Sales_item():i(0),f(0){};
    Sales_item(int _i, double _f):i(_i),f(_f){};
    virtual ~Sales_item(){};
    Sales_item operator+(const Sales_item& a, const Sales_item& b);
    /* data */
};

#endif
