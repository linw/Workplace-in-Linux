/*
 * =====================================================================================
 *
 *       Filename:    singleton.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-5-5 10:45:02
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */ 
#include <iostream>
using namespace std;
#ifndef _SOMETHING_FANTASTIC_SINGLETON_H
#define _SOMETHING_FANTASTIC_SINGLETON_H

class Singleton{
private:
    static Singleton *p;
public:
    Singleton(){ }
    virtual ~Singleton(){
        if(p!=NULL){
            delete p;
            p = NULL;
        }
    }
    static Singleton * getInstance(){
        if(p == NULL){
            p = new Singleton;
        }
        if(p == NULL){return 0;}
        return p;
    }
};
Singleton* Singleton::p = NULL;
#endif

int main(){
    Singleton *p = Singleton::getInstance();
    Singleton *q = Singleton::getInstance();
    cout<<(void*)p<<endl;
    cout<<(void*)q<<endl;
    delete p;
    delete q;
    p = q = NULL;
    int *pp[4];
    cout<<"size of pp"<<sizeof(pp)<<endl;

    return 0;
}
