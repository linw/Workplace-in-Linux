/*
 * =====================================================================================
 *
 *       Filename:    Screen.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2011年12月29日 11时09分06秒
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include "Screen.h"
#include <ostream>
Screen::Screen(const std::string &_contents, const index _width, const index _height)
{
  contents = _contents;
  width = _width;
  height = _height;
};

Screen& Screen::move(const index &x, const index &y){
  width += x;
  height += y;
  return *this;
};

Screen& Screen::set(const std::string &s){
  contents = s;
  return *this;
};


const Screen& Screen::display(std::ostream &o) const{
  o<<"position is : x = "<<width<<", y = "<<height<<std::endl;
  o<<"contents is : "<<contents<<std::endl;
  return *this;
};

