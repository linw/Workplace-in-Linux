/*
 * =====================================================================================
 *
 *       Filename:    13_10.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012年3月20日21:47:35
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
using namespace std;
class Employee{
private:
    static long init_id;
    long e_id;
    string e_name;
public:
    Employee(){
        e_id = init_id++;
        e_name = string();
    };
    Employee(const string& _name){
        e_id = init_id++;
        e_name = string(_name);
    };
public:
    long get_e_id(){
        return e_id;
    };
    string get_e_name(){
        return e_name;
    };
};
long Employee::init_id = 0;



////////////////////////////////////////////////////////////////////////////////
int main(int argc, char const *argv[])
{
    /* code */
    Employee a;
    Employee b;
    Employee c("lin wei");
    cout<<a.get_e_id()<<endl;
    cout<<b.get_e_id()<<endl;
    cout<<c.get_e_id()<<endl;
    cout<<c.get_e_name()<<endl;
    return 0;
}
