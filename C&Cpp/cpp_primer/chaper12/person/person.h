/*
 * =====================================================================================
 *
 *
 *       Filename:    person.h
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2011年12月23日 22时02分39秒
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#ifndef _CHAPER12_PERSON_H
#define _CHAPER12_PERSON_H
#include <string>
class Person{
private:
  std::string name;
  std::string address;
public:
  Person(const std::string _name="null", const std::string _address= "null")
    : name(_name), address(_address) { };
  virtual ~Person() { };
  bool print_info(); 
  bool modify_info(const std::string _name,
                   const std::string _address);
  const std::string get_name();
  const std::string get_address();
};
#endif
