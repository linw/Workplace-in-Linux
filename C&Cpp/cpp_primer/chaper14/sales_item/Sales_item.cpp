/*
 * =====================================================================================
 *
 *       Filename:    Sales_item.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-5 10:15:27
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
 #include "Sales_item.h"
 // visrtual Sales_item::~Sales_item(){};
 Sales_item Sales_item::operator+(const Sales_item& a, const Sales_item& b){
    return Sales_item(a.i+b.i, a.f+b.f);
 };
