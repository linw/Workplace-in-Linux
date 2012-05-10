#include <iostream.h>
// using namespace std;
class A{
public:
    A(){std::cout<<"A()"<<std::endl;}
    ~A(){std::cout<<"~A()"<<std::endl;}
};
A a;
int main()
{
    return 0;
}
   
