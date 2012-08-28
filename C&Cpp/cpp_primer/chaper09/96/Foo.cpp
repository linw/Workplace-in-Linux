/*
 * File name: Foo.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-11-26
 *
 */
#include <iostream>
#include "Foo.h"
using namespace std;
Foo::Foo(int i){
    cout<<i<<"st Foo"<<endl;
    this->i = i;
};
void Foo::print(){
    cout<<i<<"st Foo"<<endl;
};
