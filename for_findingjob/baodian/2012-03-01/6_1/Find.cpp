#include <iostream>
using namespace std;
struct Student 
{
    int a;
    char b[20];
    double cc;
};
//FIND(Student,a)  ���Ϊ0
//FIND(Student,b)  ���Ϊ4
//��FIND�Ķ���
#define FIND(struc, e) (size_t)(&(((struc*)0)->e))


//һ�����ж�����
//�������UL������
//#define SECONDS_PER_YEAR (365 * 24 * 3600)UL
#define SECONDS_PER_YEAR (365 * 24 * 3600)


//���ú궨��MIN
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