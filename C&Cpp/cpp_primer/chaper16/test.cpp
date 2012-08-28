/*
 * =====================================================================================
 *
 *       Filename:    test.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-19 19:56:19
 *       Compiler:    gcc
 *       Description: testing template
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
using namespace std;

template < typename Type>
class A{
public:
    A() { };
    virtual ~A() { };
    Type get_i();
    void set_i(Type ii);
    void print();
private:
    Type i;
};

template < typename Type>
Type A< Type>::get_i(){
    return i;
}

template < typename Type>
void A< Type>::set_i(Type ii){
    i = ii;
}

template < typename Type>
void A< Type>::print(){
    cout<<i<<endl;
}

int main(int argc, char const *argv[])
{
    A< int> a;
    a.set_i(10);

    A< string> b;
    b.set_i("hello");

    cout << a.get_i() << endl;
    a.print();

    cout << b.get_i() << endl;
    b.print();

    return 0;
}