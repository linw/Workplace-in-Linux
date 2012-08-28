/*
 * =====================================================================================
 *
 *       Filename:    test.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-5 11:28:54
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
// #include <iostream>
// using namespace std;
// class A
// {
// public:
//     A(){};
//     virtual ~A(){};
//     virtual void print(){
//         cout<<"helloA"<<endl;
//     };

//     /* data */
// };

// class B:public A
// {
// public:
//     B(){};
//     ~B(){};
//     void print(){
//         cout<<"helloB"<<endl;
//     };

//     /* data */
// };
// int main()
// {
//     cout<<"hello"<<endl;
//     A a;
//     a.print();
//     B& b = (B&)a;
//     b.print();
//     return 0;
// }
#include <iostream>
using namespace std;
// static int _count = 0;

// int Fibonacci(int n){
//     ++_count;
//     if(n == 0) return 0;
//     if(n == 1) return 1;
//     else return Fibonacci(n-1) + Fibonacci(n-2);
// }

// int Fibonacci_s(int n){
//     int fn = 0;
//     int fn_1;
//     int fn_2;
//     if(n == 0) { ++_count; fn = 0;}
//     else if(n == 1) { ++_count; fn = 1;}
//     else{
//         fn_1 = 1;
//         fn_2 = 0;
//         for(int i = 2; i <= n; ++i){
//             ++_count;
//             fn = fn_1 + fn_2;
//             fn_2 = fn_1;
//             fn_1 = fn;
//         }
//     }
//     return fn;
// }

// bool _is_space(const char& c){
//     if(c == ' ' || c == '\t' || c == '\n')
//         return true;
//     else return false;
// }
// bool _is_digit(const char& c){
//     if(c<='9'&&c>='0')
//         return true;
//     return false;
// }
// long my_atoi(const char* str){
//     int flag = 1;
//     long sum = 0;
//     while(_is_space(*str)){
//         ++str;
//     }
//     if(*str == '-') {flag = -1;str++;}
//     else if(*str == '+') {flag = 1;str++;}
//     else if(*str >'9' ||*str < '0'){
//         sum = 0;
//         return sum;
//     }
//     while(_is_digit(*str)){
//         sum = sum*10 + *str - '0';
//         ++str;
//     }
//     if(*str != '\0') sum = 0;
//     return flag>0?sum:-sum;
// }

// int main()
// {
//     // _count = 0;
//     // cout<<Fibonacci(10) << "  count:" << _count << endl;
//     // _count = 0;
//     // cout<<Fibonacci_s(10) << "  count:" << _count << endl;
//     cout<<my_atoi("\n \t-12as310")<<endl;
//     return 0;
// }

class A{
public:
    int i;
    void print(){ cout<<"A"<<endl;}
};

class AA{
    void print(){ cout<<"AA"<<endl;}
};

class B:public virtual A{
};

class C:public virtual A{
};

class D:public B, public C{
};

int main(int argc, char const *argv[])
{
    // cout<<sizeof(B)<<endl;
    D d;
    cout<<sizeof(d)<<endl;
    cout<<d.i<<endl;
    d.i = 10;
    cout<<d.i<<endl;
    return 0;
}