/*
 * =====================================================================================
 *
 *       Filename:    12_41.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年3月19日21:09:38
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;
class Foo{
private:
    int foo_i;
public:
    Foo(const int& _i){
        foo_i = _i;
    }
    virtual ~Foo(){};
public:
    int get_i(){
        return foo_i;
    }
};

class Bar{
public:
    static int bar_i;
    static Foo bar_f;
public:
    Bar(){};
    virtual ~Bar(){};
};

int Bar::bar_i = 20;
Foo Bar::bar_f = Foo(0);
int main()
{
    Bar a;
    return 0;
}