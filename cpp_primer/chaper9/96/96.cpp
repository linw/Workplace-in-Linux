/*
 * File name: 96.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-11-26
 *
 */
#include <iostream>
#include <list>
#include "Foo.h"
using namespace std;
void showFun(){
    list<Foo> flist;
    for(list<Foo>::size_type i = 0; i < 10; ++i){
        Foo f(i);
        flist.push_back(f);
    }
    for(list<Foo>::iterator iter = flist.begin(); 
                            iter != flist.end();
                            ++iter){
        iter->print();
    }
}
int main()
{
    showFun(); 
    return 0;
}

