/********************************************************************
	created:	2012/03/02
	created:	2:3:2012   10:16
	filename: 	E:\FINDJOB\PROGRAM\面试宝典\2012-03-01\Chaper06\内存对齐\main.cpp
	file path:	E:\FINDJOB\PROGRAM\面试宝典\2012-03-01\Chaper06\内存对齐
	file base:	main
	file ext:	cpp
	author:		linwei
	
	purpose:	对内存对齐相关扩展知识
*********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a;
    char b;
    int c;
    printf("0x%08x\n",&a);
    printf("0x%08x\n",&b);
    printf("0x%08x\n",&c);
    printf("%d\n",sizeof(bool));
//     int c = 20;
//     size_t i=0;
//     cout<<hex<<c<<endl;
//     cout<<hex<<(unsigned(c)>>31)<<endl;
//        float a = 1.0f;
//        cout<<(int)&a<<endl;


    return 0;
}
