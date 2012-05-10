/********************************************************************
	created:	2012/03/01
	created:	1:3:2012   21:28
	filename: 	E:\FINDJOB\PROGRAM\���Ա���\2012-03-01\Chaper06\Const\main.cpp
	file path:	E:\FINDJOB\PROGRAM\���Ա���\2012-03-01\Chaper06\Const
	file base:	main
	file ext:	cpp
	author:		linwei
	
	purpose:	const�ؼ��ֵļ����÷�ѧϰ
*********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std; 


/*
 *	const��������������
 *  ��c��const�����ı���ռ���ڴ�ռ䣬���ᱻ�����ǳ�������c++�в�ռ�ã��ڱ���ʱҲΪ������
 */
const size_t n = 10;

/*
 *	const�����������еķ���
 *  ����mutable��const�������Է��ʷ�const��Ա����
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
 *	const�������κ�������ֵ
 */
const size_t& constReturn()
{
    int *a = new int;
    *a = 100;
    return *a;
}



int main()
{
    int a[n]; //const������
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