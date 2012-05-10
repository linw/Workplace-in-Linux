#include <iostream>

using namespace std;

int findMax1(const int& a, const int& b)
{
    return (a+b + abs(a-b))/2;
}

int findMax2(const int& a, const int& b)
{
    int c = a - b;
    c = unsigned(c) >> (sizeof(int) * 8 - 1);
    return c;
}


int main()
{
    cout<<findMax1(10,9)<<endl;
    return 0;
}
