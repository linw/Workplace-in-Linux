/*
 * =====================================================================================
 *
 *       Filename:    main.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     22:4:2012   20:50
 *       Compiler:    vc
 *       Description: 
 *               题目: 寻找发帖水王。条件，该水王发帖数超过帖子一半。
 *             
 *
 * =====================================================================================
 */
#include <iostream>
#define HAOHAO
using namespace std;


size_t find_most_appear_id(int a[], size_t n){
    size_t count = 0;
    int id = -1;
    for(int i = 0; i < n; ++i){
        if(count == 0)
            id = a[i];
        if(id == a[i])
            count++;
        else count--;
    }
    return id;
}


int main()
{
    int a[20] = {1,2,2,2,2,2,3,4,1,2,2,2,1,1,1,2,2,3,5,4};
    cout<<find_most_appear_id(a,20)<<endl;
    return 0;
}


#ifndef HAOHAO
#include <iostream>
using namespace std;
// class A{
// public:
//     int i;
//     virtual void print(){ i = i + 2;};
// };
class classA{
public:
    virtual ~classA(){};
    virtual void FunctionA(){};
};
class classB{
public:
    virtual void FunctionB(){};
};
class classC:public classA,public classB{
public:
};
int main(){
    classC aobject;
    classA * pa=&aobject;
    classB * pb=&aobject;
    classC * pc=&aobject;
    cout<<hex<<pa<<endl;
    cout<<hex<<pb<<endl;
    cout<<hex<<pc<<endl;
    return 0;
}
#endif
