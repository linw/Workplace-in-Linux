/*
 * =====================================================================================
 *
 *       Filename:    smart_point_test_class.h
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年3月21日23:03:20
 *       Last Edit:   2012-3-22 17:13:05
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#ifndef _CHAPER13_SMART_POINT_TEST_CLASS_H
#define _CHAPER13_SMART_POINT_TEST_CLASS_H
#include "smart_point.h"
class Has_smart_point
{
public:
    Has_smart_point(int *_p):ptr(new Smart_Ptr(_p)){};
    Has_smart_point(const Has_smart_point &_hsp): ptr(_hsp.ptr){ ++ptr->use;};
    Has_smart_point& operator=(const Has_smart_point&);
    virtual ~Has_smart_point(){ if(--ptr->use == 0) delete ptr;}


    int get_use_status(){ return ptr->use;}
private:
    Smart_Ptr *ptr;
    /* data */
};

#endif
