/*
 * =====================================================================================
 *
 *       Filename:    smart_point_test_class.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-3-22 17:20:26
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include "smart_point_test_class.h"
Has_smart_point& Has_smart_point::operator=(const Has_smart_point& _hsp){
    ++_hsp.ptr->use;
    if(--ptr->use == 0)
        delete ptr;
    ptr = _hsp.ptr;
    return *this;
}
