/*
 * =====================================================================================
 *
 *
 *       Filename:    x_and_y.h
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2011年12月29日 11时20分59秒
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#ifndef _CHAPER12_XANDY_H
#define _CHAPER12_XANDY_H
class Y;
class X;
class X{
public:
  Y *y;
};
class Y{
public:
  X x;
};
#endif
