/*
 * =====================================================================================
 *
 *       Filename:    13_4.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年3月20日13:56:42
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
using namespace std;
struct NoName {
    NoName(): pstring(new std::string), i(0), d(0){ }
    NoName(const NoName& _nn);
    NoName& operator=(const NoName&);
//private:
    std::string *pstring;
    int i;
    double d;
};

NoName::NoName(const NoName& _nn){
    pstring = new string(*(_nn.pstring)) ;
    i = _nn.i;
    d = _nn.d;  
//    cout<<"test"<<endl; 
}

NoName& NoName::operator=(const NoName& _nn){
    cout<<"hello"<<endl;
    pstring = new string(*(_nn.pstring)) ;
    i = _nn.i;
    d = _nn.d;      
    return *this;     
}

int main()
{
    NoName a;
    a.pstring = new string("hello");
    NoName b ;
    a = b;
    cout<<a.pstring<<endl;
    cout<<b.pstring<<endl;
    cout<<*(b.pstring)<<endl;
    return 0;
}
