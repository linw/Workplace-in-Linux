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
##ifndef  _CHAPER13_SMART_POINT_H
#define _CHAPER13_SMART_POINT_H
class Smart_Ptr
{
    int *ip;
    size_t use;
    Smart_Ptr(int *ip): ip(p), use(1){ };
    virtual ~Smart_Ptr();    
};
#endif