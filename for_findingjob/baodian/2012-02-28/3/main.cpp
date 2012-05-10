#include "stdio.h"
#include <iostream>
using namespace std;


int main()
{
    unsigned int a = 0xffffff77;
    char* b = (char*)(&a);
    printf("%08x",*b);
    return 0;
}
