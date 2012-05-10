/********************************************************************
	created:	2012/03/09
	created:	9:3:2012   11:10
	filename: 	E:\findjob\program\baodian\chaper07\test\main.cpp
	file path:	E:\findjob\program\baodian\chaper07\test
	file base:	main
	file ext:	cpp
	author:		lin wei
	
	purpose:	
*********************************************************************/


#include <iostream>
using namespace std;

int main()
{
    const int a = 10;
    int* b = (int*)&a;
    (*b) ++;
    cout<<*b<<endl;
    cout<<a<<endl;


    //Àí½âchar* str ºÍ char str[]
    char c[] = "hello world!";
    char *cp = "hello world!";
    char *str = "hello worl!";
    cout<<(void*)c<<endl;
    cout<<(void*)cp<<endl;
    cout<<(void*)str<<endl;
//    cp[1] = 'k';
//    c[1] = 'k';


    int *ptr;
    ptr = (int*)0x8000;
    *ptr = 0xaabb;
    return 0;
}
