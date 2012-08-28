/*
 * =====================================================================================
 *
 *       Filename:    test.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年3月18日20:58:32
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */

 #include <iostream>
 using namespace std;

class B{
public:
    void print();
};

class A{
    friend class B;
private:
    void print1();
};

void B::print(){
    cout<<"hello"<<endl;
    A a;
    a.print1();
};
void A::print1(){
    cout<<"print1"<<endl;
}


int main()
{
    B b;
    b.print();
    return 0;
}
