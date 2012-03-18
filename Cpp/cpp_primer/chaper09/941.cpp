/*
 * File name: 941.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-6 
 *
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;
string greet(string form, string lastname, string title,
             string::size_type pos, int length)
{
    string::size_type pos1 = 0;
    string::size_type lnLength = lastname.size();
    cout<<lnLength<<endl;
    while((pos1 = form.find("Daisy",pos1))
               != string::npos)
    {
        cout<<form.c_str()<<endl;
        form.replace(pos1, 5, lastname);
        pos1 = pos1 + lnLength;
    }
    pos1 = 0;
    string tmp = title.substr(pos, length);
//    cout<<tmp.c_str()<<endl;
//    cout<<form.c_str()<<endl;
    while((pos1 = form.find("Ms", pos1))
               != string::npos)
    {
        form.replace(pos1, 2, tmp);
//        cout<<length<<endl;
        pos1 = pos1 + length;
    }
    return form;
}
int main()
{
    string generic1("Dear Ms Daisy:");
    string generic2("MrsMsMissPeople");
    string lastName("AnnaP");
    string salute = greet(generic1, lastName, generic2, 5, 4);
    cout<<salute.c_str()<<endl;
    return 0;
}

