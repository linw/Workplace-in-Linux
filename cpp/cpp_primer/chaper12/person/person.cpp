/*
 * =====================================================================================
 *
 *       Filename:    person.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2011年12月23日 22时02分54秒
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include <iostream>
#include "person.h"
bool Person::print_info()
{
  std::cout<<"==========person information=========="<<std::endl;
  std::cout<<"name:"<<name<<std::endl;
  std::cout<<"address:"<<address<<std::endl;
  std::cout<<"======================================"<<std::endl;
  return true;
};
bool Person::modify_info(const std::string _name,
  const std::string _address)
{
  name = _name;
  address = _address;
  return true;
};
const std::string Person::get_name()
{
  return name;
};
const std::string Person::get_address()
{
  return address;
};
