#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
int main()
{
    float a = 1.0f;
    cout<<(int)a<<endl;
    cout<<(int&)a<<endl;
    cout<<boolalpha<<((int)a == (int&)a)<<endl;

    float b = 0.0f;
    cout<<(int)b<<endl;
    cout<<(int&)b<<endl;
    cout<<boolalpha<<((int)b == (int&)b)<<endl;
    return 0;
}