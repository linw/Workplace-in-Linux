#include <iostream>
#include <conio.h>
using namespace std;
bool func(const int& x)
{
    return !(x&(x-1));
}


int main()
{
    cout<<boolalpha<<func(4096)<<endl;
    return 0;
}