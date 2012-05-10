#include <iostream>
using namespace std;

void swap_a_b1(int& a, int& b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
void swap_a_b2(int& a, int& b)
{
    a = a^b;
    b = a^b;
    a = a^b;
}



int main()
{
    int a = 10, b = 20;
    swap_a_b1(a,b);
    cout<<a<<" "<<b<<endl;
    swap_a_b2(a,b);
    cout<<a<<" "<<b<<endl;
    return 0;
}