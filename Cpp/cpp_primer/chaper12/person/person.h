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
    Person(): name("null"), address("null") { }
    
}
#endif
