/********************************************************************
	created:	2012/03/08
	created:	8:3:2012   21:16
	filename: 	E:\FINDJOB\PROGRAM\BAODIAN\chaper06\testSizeof\main.cpp
	file path:	E:\FINDJOB\PROGRAM\BAODIAN\chaper06\testSizeof
	file base:	main
	file ext:	cpp
	author:		lin wei
	
	purpose:	learning sizeof
*********************************************************************/

#include <iostream>
using namespace std;

int test(char var[]){
    return sizeof(var);
};

int main()
{
    char var[10];
    cout<<test(var)<<endl;
}
