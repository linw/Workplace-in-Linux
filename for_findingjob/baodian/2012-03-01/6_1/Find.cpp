#include <iostream>
using namespace std;
struct Student 
{
    int a;
    char b[20];
    double cc;
};
//FIND(Student,a)  结果为0
//FIND(Student,b)  结果为4
//对FIND的定义
#define FIND(struc, e) (size_t)(&(((struc*)0)->e))


//一年中有多少秒
//这里加入UL有问题
//#define SECONDS_PER_YEAR (365 * 24 * 3600)UL
#define SECONDS_PER_YEAR (365 * 24 * 3600)


//利用宏定义MIN
#define MIN(A,B) ((A)<(B)?(A):(B))


int main()
{
    cout<<FIND(Student,cc)<<endl;
//    cout<<SECONDS_PER_YEAR<<endl;
    long a = SECONDS_PER_YEAR;
    cout<<a<<endl;
    cout<<MIN(10,5)<<endl;
    return 0;
}