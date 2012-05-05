/*
 * File name: 101.cpp
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2011-12-7 
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int main()
{
    vector<pair<string, int> > vpair;
    string s;
    int key;
    while(cin>>s>>key)
        vpair.push_back(make_pair(s, key));
    for(vector<pair<string, int> >::const_iterator iter = vpair.begin();
                                                   iter != vpair.end();
                                                   ++iter)
    {
        cout<<iter->first.c_str()<<"  "<<iter->second<<endl;
    }
    return 0;
}
