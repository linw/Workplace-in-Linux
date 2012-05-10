#include <iostream>
using namespace std;
int func(int x)
{
    int count = 0;
    while(x){
        count ++;
        x = x&(x-1);
    }
    return count;
}

int main()
{
    cout<<func(9999)<<endl;
    return 0;
}