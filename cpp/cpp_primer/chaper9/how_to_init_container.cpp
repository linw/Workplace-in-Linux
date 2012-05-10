#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
using namespace std;
void initVector(){
   vector<string> svec(10,"king");
   vector<string> svec1(svec);
   vector<string> svec2(svec.begin(),svec.end());
   vector<string> svec3(10);
   cout<<"svec is:"<<endl;
   for(vector<string>::iterator iter = svec.begin(); 
            iter != svec.end();
            ++iter){
       cout<<(*iter).c_str()<<endl;
   }

   cout<<"svec1 is:"<<endl;
   for(vector<string>::iterator iter = svec1.begin(); 
            iter != svec1.end();
            ++iter){
       cout<<(*iter).c_str()<<endl;
   }

   cout<<"svec2 is:"<<endl;
   for(vector<string>::iterator iter = svec2.begin(); 
            iter != svec2.end();
            ++iter){
       cout<<(*iter).c_str()<<endl;
   }


   cout<<"svec3 is:"<<endl;
   for(vector<string>::iterator iter = svec3.begin(); 
            iter != svec3.end();
            ++iter){
       cout<<(*iter).c_str()<<endl;
   }
   
}

void initList(){
    list<int> ilist(10);
    list<int> ilist1(ilist);
    list<int> ilist2(10,19);
    list<int> ilist3(ilist2.begin(),ilist2.end());

   cout<<"ilist is:"<<endl;
   for(list<int>::iterator iter = ilist.begin(); 
            iter != ilist.end();
            ++iter){
       cout<<(*iter)<<endl;
   }

   cout<<"ilist1 is:"<<endl;
   for(list<int>::iterator iter = ilist1.begin(); 
            iter != ilist1.end();
            ++iter){
       cout<<(*iter)<<endl;
   }

   cout<<"ilist2 is:"<<endl;
   for(list<int>::iterator iter = ilist2.begin(); 
            iter != ilist2.end();
            ++iter){
       cout<<(*iter)<<endl;
   }
   cout<<"ilist3 is:"<<endl;
   for(list<int>::iterator iter = ilist3.begin(); 
            iter != ilist3.end();
            ++iter){
       cout<<(*iter)<<endl;
   }
}

void initDeque(){

    deque<int> ideque(10);
    deque<int> ideque1(ideque);
    deque<int> ideque2(10,19);
    deque<int> ideque3(ideque2.begin(),ideque2.end());

   cout<<"ideque is:"<<endl;
   for(deque<int>::iterator iter = ideque.begin(); 
            iter != ideque.end();
            ++iter){
       cout<<(*iter)<<endl;
   }

   cout<<"ideque1 is:"<<endl;
   for(deque<int>::iterator iter = ideque1.begin(); 
            iter != ideque1.end();
            ++iter){
       cout<<(*iter)<<endl;
   }

   cout<<"ideque2 is:"<<endl;
   for(deque<int>::iterator iter = ideque2.begin(); 
            iter != ideque2.end();
            ++iter){
       cout<<(*iter)<<endl;
   }
   cout<<"ideque3 is:"<<endl;
   for(deque<int>::iterator iter = ideque3.begin(); 
            iter != ideque3.end();
            ++iter){
       cout<<(*iter)<<endl;
   }
}
int main()
{
    initVector();
    initList();
    initDeque();
    return 0;
}
