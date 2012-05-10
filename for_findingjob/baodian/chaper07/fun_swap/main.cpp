/********************************************************************
	created:	2012/03/09
	created:	9:3:2012   11:36
	filename: 	E:\FINDJOB\PROGRAM\BAODIAN\chaper07\fun_swap\main.cpp
	file path:	E:\FINDJOB\PROGRAM\BAODIAN\chaper07\fun_swap
	file base:	main
	file ext:	cpp
	author:		lin wei
	
	purpose:	实现c++中的变量交换任务
*********************************************************************/

#include <iostream>
using namespace std;

void swap_1(int p, int q){
    p = p^q;
    q = p^q;
    p = p^q;
}

void swap_2(int *p, int *q){
    (*p) = (*p)^(*q);
    (*q) = (*p)^(*q);
    (*p) = (*p)^(*q);
}

void swap_3(int *p, int *q){
    int *temp;
    temp = p;
    p = q;
    q = temp;
}

void swap_4(int& p, int& q){
    p = p^q;
    q = p^q;
    p = p^q;
}

int main()
{
    int a = 2;
    int b = 4;
    swap_1(a,b);
    swap_2(&a,&b);
    swap_3(&a,&b);
    swap_4(a,b);
    cout<<a<<" "<<b<<endl;
}