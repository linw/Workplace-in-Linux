/*
 * File name: 928.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-6 
 *
 */
#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void CharToStringContainer(const list<char*> &source,
                           vector<string> &target)
{
    for(list<char*>::const_iterator iter = source.begin();
                                    iter != source.end();
                                    ++iter)
    {
      cout<<*iter<<endl;
      string s(*iter); 
      target.push_back(s);
    }
}

int main()
{
    char* a[]={"linwei", "linv", "linw", "king", "chihao"};
    list<char*> source(a, a+5);
//    cout<<"list capacity:"<<source.capacity()<<endl;
    vector<string> target;
    CharToStringContainer(source, target);
    cout<<target.size()<<endl;
    cout<<"capacity:"<<target.capacity()<<endl;
    return 0;
}
