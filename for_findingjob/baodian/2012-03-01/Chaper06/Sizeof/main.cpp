/********************************************************************
	created:	2012/03/01
	created:	1:3:2012   22:44
	filename: 	E:\FINDJOB\PROGRAM\面试宝典\2012-03-01\Chaper06\Sizeof\main.cpp
	file path:	E:\FINDJOB\PROGRAM\面试宝典\2012-03-01\Chaper06\Sizeof
	file base:	main
	file ext:	cpp
	author:		linwei
	
	purpose:	主要用于学习关于sizeof的相关知识
*********************************************************************/

#include <iostream>
#include "stdio.h"
#include <string.h>
using namespace std;
struct{
    short a1;
    short a2;
    short a3;
}A;

struct{
    long a1;
    short a2;
}B;

int main()
{
    char* ss1 = "0123456789";
    char ss2[] = "0123456789";
    char ss3[100] = "0123456789";
    int ss4[100];
    char q1[]="abc";
    char q2[]="a\n";
    char* q3 = "a\n";
    char *str1 = (char *)malloc(100);
    void *str2 = (void *) malloc(100);

    cout<<sizeof(ss1)<<endl;
    cout<<sizeof(ss2)<<endl;
    cout<<sizeof(ss3)<<endl;
    cout<<sizeof(ss4)<<endl;
    cout<<sizeof(q1)<<endl;
    cout<<sizeof(q2)<<endl;
    cout<<sizeof q3<<endl;
    cout<<sizeof A <<endl;
    cout<<sizeof B <<endl;
    cout<<sizeof(str1)<<endl;
    cout<<sizeof(str2)<<endl;
    free(str1);
    free(str2);

    char a[] = "0123456789";
    cout<<sizeof(a)<<endl;
    int king[sizeof(a)];
    cout<<strlen(a)<<endl;
//    int king1[strlen(a)];
    string str ;
    cout<<"str"<<sizeof(str)<<endl;
    string astr[10];
    cout<<sizeof(astr)<<endl;
    return 0;

}



