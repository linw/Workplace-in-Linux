/********************************************************************
	created:	2012/03/08
	created:	8:3:2012   21:29
	filename: 	E:\FINDJOB\PROGRAM\BAODIAN\chaper06\virtualFunction\main.cpp
	file path:	E:\FINDJOB\PROGRAM\BAODIAN\chaper06\virtualFunction
	file base:	main
	file ext:	cpp
	author:		lin wei
	
	purpose:	test virtual function
*********************************************************************/
#include <iostream>
using namespace std;
class Base1
{
public:
    virtual ~Base1(){cout<<"Base1"<<endl;};
    virtual void fun(){cout<<"hello"<<endl;};
/*    inline void fun1(){cout<<"hello"<<endl;};*/
    inline void fun2()
    {
        for(int i = 0; i < 10; ++i){
            cout<<"fun2"<<endl;
        }
}
};

class Derived1: public Base1
{
public:
    ~Derived1(){cout<<"Derived1"<<endl;}
};
// inline void fun2()
// {
//     for(int i = 0; i < 10; ++i){
//     cout<<"fun2"<<endl;
//     }
// }
int main()
{
    Base1 *bp = new Derived1;

    cout<<sizeof(Base1)<<endl;
    bp->fun2();

        delete bp;
    return 0;
}
