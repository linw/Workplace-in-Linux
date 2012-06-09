/*
 * =====================================================================================
 *
 *       Filename:    reverse_words.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-5-14 10:18:27
 *       Compiler:    gcc
 *       Description:
 *              题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
 *                   句子中的单词以空格符隔开，为简单起见，标点符号和普通字母一样处理
 *              理解：也是一个字符串翻转问题
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
using namespace std;
// reverse char* function
char* reverse(char* str, const unsigned int len)
{
  int i,j;
  char tmp;
  for(i=0;i<len;++i)
    if(str[i] == '\0')
      assert(0);
  for(i=0,j=len-1;i<j;++i,--j){
    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
  }
  return str;
}

char* reverse_sentence(char* str)
{
  int i,j;
  unsigned int  start;
  unsigned int len;
  unsigned int n;
  // find how long the string is.
  for(n = 0; str[n]!='\0';++n)
    ;
  start = 0;
  for(i = 0; i <= n; ++i){
    if(str[i] == ' '||str[i] == '\0'){
      reverse(str+start,i-start);
      start = i+1;
      cout<<str+start<<endl;
    }
  }
  reverse(str,n);
  return str;
}


int main()
{
  char a[] = "I am a student.";
  reverse_sentence(a);
  cout<<a<<endl;
  return 0;
}

