/*
 * =====================================================================================
 *
 *       Filename:    reverse_stack.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-10-04 16:12:44
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */

#include <iostream>
#include <stack>
using namespace std;

template <typename T>
void reverseStack(std::stack<T>& t_stack)
{
  if(!t_stack.empty()){
    T top = t_stack.top();
    t_stack.pop();
    reverseStack(t_stack);
    addToBottom(t_stack, top);
  }
}
template <typename T>
void addToBottom(std::stack<T>& t_stack, T& e)
{
  if(t_stack.empty()){
    t_stack.push(e);
  }
  else {
    T top;
    top = t_stack.top();
    t_stack.pop();
    addToBottom(t_stack,e);
    t_stack.push(top);
  }
}

int
main(void)
{
  std::stack<int> i_stack;

  for(int i = 0; i < 10; ++i){
    i_stack.push(i);
  }
  // while(!i_stack.empty()){
  //   cout<<i_stack.top()<<endl;
  //   i_stack.pop();
  // }
  reverseStack(i_stack);
  while(!i_stack.empty()){
    cout<<i_stack.top()<<endl;
    i_stack.pop();
  }
  return 0;
}
