#include <iostream>
using namespace std;
class A{
    double a;
    float b;
    int c;
    char d;
};
int main()
{
    cout<<sizeof(A)<<endl;
    cout<<sizeof(double)<<endl;
    return 0;
}