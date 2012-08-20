/*
 * =====================================================================================
 *
 *       Filename:    number_to_word.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-5-23 10:59:14
 *       Compiler:    gcc
 *       Description: 
 *               题目：输入一段数字，这段数字所对应的手机上可以输出的字母  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char c[10][5]={
  "",                 //0
  "",                 //1
  "ABC",              //2
  "DEF",              //3
  "GHI",              //4
  "JKL",              //5
  "MNO",              //6
  "PQRS",             //7
  "TUV",              //8
  "WXYZ"              //9
};

int c_len[10] = {0,0,3,3,3,3,3,4,3,4};

// solutation1: 利用循环打印出全部可能性
void print_number_to_word_1(const int * const a, const int n)
{
  int i,j;
  int *answer;
  answer = (int *) malloc(sizeof(int)*n);
  for(i = 0; i < n; ++i)
    answer[i] = 0;
  while(1){
    for(i = 0; i < n; ++i)
      printf("%c",c[a[i]][answer[i]]);
    printf("\n");
    j = n - 1;
    while(j>=0){
      if(answer[j]<c_len[a[j]]-1){
        ++answer[j];
        break;
      }
      else {
        answer[j] = 0;
        --j;
      }
    }
    if(j < 0)
      break;
  }
}

// solutation2: 利用递归
void number_to_word_2(const int * const a, int *answer,int n, int index){
  int i;
  if(index == n){
    for(i = 0; i < n; ++i){
      printf("%c",c[a[i]][answer[i]]);
    }
    printf("\n");
    return;
  }
  for(answer[index] = 0; answer[index] < c_len[index]; ++answer[index])
  {
    number_to_word_2(a,answer,n,index+1);
  }
  for(i = 0; i < n; ++i){
    printf("%c",c[a[i]][answer[i]]);
  }
}

void print_number_to_word_2(const int * const a, const int n)
{
  int *answer;
  int i;
  answer = (int*) malloc(sizeof(int)*n);
  for(i = 0; i < n; ++i)
    answer[i] = 0;
  number_to_word_2(a,answer,n,0);
  free(answer);
}


main()
{
  int a[] = {1,2,3,4};
  // print_number_to_word_1(a,4);
  print_number_to_word_2(a,4);
}
