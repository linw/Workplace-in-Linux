#include <iostream>
#include "stdio.h"
#include <string>
using namespace std;
class A{
public:
    static int i;
    double a;
    float b;
    int c;
    char d;
};

class B:public A{
public:
    // static int i;
};
union K{
    int i;
    double k;
    char c;
};
class AA{
public:
    virtual void print(){cout<<"king"<<endl;}
    virtual void print1(){cout<<"king"<<endl;}
};

class BB:public AA{
public:
    void print(){cout<<"BB"<<endl;}
    virtual void print2(){cout<<"BB1"<<endl;}
};

// struct S {
//     int i;
//     int *p;
// };
int A::i = 0;
// int B::i = 0;

int fun(std::string s)
{
  cout<<s.c_str()<<endl;
}
int main()
{
    // // cout<<sizeof(A)<<endl;
    // // cout<<sizeof(double)<<endl;
    // // cout<<1.0/3.0<<endl;
    // int i = 0;
    // for (printf("A"); printf("B")&&(i < 2); printf("C"))
    // {
    //     /* code */
    //     i++;
    //     printf("D");
    // }
    // char ss[] = "ABCDEFG";
    // char* ss1 = "ABCDEFG";
    // ss1[1] = 'k';  
    // cout<<endl<<"SS1:"<<ss1<<endl;
    // cout<<hex<<(void *)ss1<<endl;
    // cout<<hex<<(void *)ss<<endl;


    // cout<<endl<<strlen(ss)<<endl;
    // cout<<endl<<sizeof(ss)<<endl;
    // K k;
    // k.c = 'a';
    // cout<<sizeof(k)<<endl;
    // cout<<k.c<<endl;
    // string str = "king";
    // cout<<sizeof(str)<<endl;
    // printf("%p\n", &A::a);
    // printf("%p\n", &A::b);
    // printf("%p\n", &A::c);
    // printf("%p\n", &A::d);


    // // S s;
    // // int *p = &s.i;
    // // p[0] = 4;
    // // p[1] = 3;
    // // cout<<"1h"<<endl;
    // // s.p = p;
    // // cout<<"2h"<<endl;
    // // s.p[1] = 1;
    // // cout<<"3h"<<endl;
    // // s.p[2] = 2;
    // // cout<<"4h"<<endl;
    // cout<<sizeof("")<<endl;
    // int a[] = {1,2,3,4,5};
    // int *ptr = (int*)(&a + 1);
    // cout<<hex<<(void*)&a<<endl;
    // cout<<hex<<(void*)a<<endl;
    // printf("%d %d\n", *(a + 1), *(ptr -1));


    // A a;
    // a.i = 10;
    // B b;
    // b.i = 20;
    // cout<<hex<<&A::i<<endl;
    // cout<<hex<<&B::i<<endl;
    AA a;
    cout<<sizeof(a)<<endl;
    cout<<sizeof(BB)<<endl;
    char *p = "Hello world!!!";
    string s = string(p);
    cout<<s.c_str()<<endl;
    //  fun("hello");
    fun(s);


    

    return 0;
}
