/*
 * =====================================================================================
 *
 *       Filename:    12_38_39_40.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年3月18日22:35:50
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

//12.38题目要求
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

//12.39题目要求
class Bar{
public:
    static int bar_i;
    static Foo bar_f;
public:
    Bar(){};
    virtual ~Bar(){};
};

//12.40题目要求
class EBar:public Bar{
private:
    static size_t ebar_count;
public:
    EBar(){};
    virtual ~EBar(){};
public:
    int FooVal(){
        ebar_count++;
        return Bar::bar_i; 
    }
    size_t callsFooVal(){
        return ebar_count;
    };

};

int Bar::bar_i = 0;
Foo Bar::bar_f = Foo(0);
size_t EBar::ebar_count = 0;

int main()
{
    EBar a;
    cout<<a.FooVal()<<endl;
    cout<<a.FooVal()<<endl;
    cout<<a.FooVal()<<endl;
    cout<<a.callsFooVal()<<endl;
    return 0;
}
