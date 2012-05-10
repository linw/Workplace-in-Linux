#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    ifstream iin("readme.txt");
    if(!iin.is_open())
        cout<<"error!"<<endl;
    char* a = new char[1000];
    iin.getline(a,0);
    return 0;
}