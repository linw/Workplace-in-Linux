/********************************************************************
	created:	2012/03/01
	created:	1:3:2012   21:28
	filename: 	E:\FINDJOB\PROGRAM\面试宝典\2012-03-01\Chaper06\Const\main.cpp
	file path:	E:\FINDJOB\PROGRAM\面试宝典\2012-03-01\Chaper06\Const
	file base:	main
	file ext:	cpp
	author:		linwei
	
	purpose:	const关键字的几种用法学习
*********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std; 


/*
 *	const用作常量的修饰
 *  在c中const申明的变量占用内存空间，不会被看成是常量。在c++中不占用，在编译时也为常量。
 */
const size_t n = 10;

/*
 *	const用于修饰类中的方法
 *  加入mutable后，const方法可以访问非const成员变量
 */
class A
{
public:
    A(int i):m_Count(i){}
    int incr() const
    {
        return ++m_Count;
    }
    int decr() const
    {
        return --m_Count;
    }

private:
    mutable int m_Count;    
};


/*
 *	const用于修饰函数返回值
 */
const size_t& constReturn()
{
    int *a = new int;
    *a = 100;
    return *a;
}



int main()
{
    int a[n]; //const做常量
    A b(10);
    for (int tmp,i=0;i<10;i++)
    {
        tmp = b.incr();
        cout<<setw(tmp)<<setfill('#')<<tmp<<endl;
    }
    cout<<setbase(4);
    cout<<1000<<endl;
    int c = constReturn();
    delete &c;
    cout<<c<<endl;
    return 0;
}