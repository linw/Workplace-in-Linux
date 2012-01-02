/*
 * =====================================================================================
 *
 *       Filename:    Screen.h
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2011年12月29日 11时09分12秒
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#ifndef _CHAPER12_SCREEN_H
#define _CHAPER12_SCREEN_H
#include <iostream>
#include <ostream>
#include <string>
class Screen{
public:
  typedef std::string::size_type index;
  Screen(const std::string &_contents, const index _width, const index _height);
  virtual ~Screen(){};
  Screen& move(const index &x, const index &y);
  Screen& set(const std::string &s);
  const Screen& display(std::ostream &o) const;
private:
  std::string contents;
  index cursor;
  index width, height;
};
#endif
