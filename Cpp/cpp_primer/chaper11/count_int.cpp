#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
using namespace std;
void InputInt(istream &in, vector<int> &ivec){
    int value = 0;
    in.clear();
    while(in>>value)
        ivec.push_back(value);
}
void InputString(istream &in, list<string> &slist){
    string s;
    in.clear();
    while(in>>s)
        slist.push_back(s);
}
int main(){
//    vector<int> ivec;
//    InputInt(cin, ivec);
//    vector<int>::iterator start = ivec.begin();
//    vector<int>::iterator end = ivec.end();
//    cout<<count(start,end,10)<<endl;
    list<string> slist;
    InputString(cin,slist);
    list<string>::iterator start_list = slist.begin();
    list<string>::iterator end_list = slist.end();
    cout<<count(start_list,end_list,"lin")<<endl;

    return 0;
}

