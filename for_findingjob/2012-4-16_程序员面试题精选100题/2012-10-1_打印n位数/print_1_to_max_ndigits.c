/*
 * =====================================================================================
 *
 *       Filename:    print_1_to_max_ndigits.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-10-01 16:05:17
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void print_long_number(const char* num){
  assert(num);
  int none_print = 1;
  while(*num){
    if(none_print){
      if(*num == '0'){
	++num;
      }
      else {
	none_print = 0;
	printf("%c",*num++);
      }
    }
    else {
      printf("%c",*num++);
    }
  }
  printf("\n");
}

void print_1_to_max_ndigits(int n)
{
  char* num;
  num = (char*)malloc(sizeof(char)*(n+1));
  memset(num, '0', n);
  num[n] = '\0';
  while(!increment(num)){
    print_long_number(num);
  }
  free(num);
}

int increment(char* num)
{
  assert(num);
  unsigned int num_len = strlen(num);
  int over_flow = 0;
  int take_over = 0;
  int i,j;
  int tmp;
  for(i = num_len - 1; i >= 0; --i){
    tmp = num[i]-'0'+take_over;
    if(i == num_len - 1){
      ++tmp;
    }
    if(tmp >= 10){
      if(i == 0){
	over_flow = 1;
      }
      else {
	tmp -= 10;
	take_over = 1;
	num[i] = tmp + '0';
      }
    }
    else {
      num[i] = tmp + '0';
      break;
    }
  }
  return over_flow;
}

void print_1_to_max_ndigits_recursively(char *num, int length, int index)
{
  int i;
  if(index == length - 1){
    print_long_number(num);
    return;
  }
  for(i = 0; i < 10; ++i){
    num[index+1] = i + '0';
    print_1_to_max_ndigits_recursively(num, length, index+1);
  }
}


void print_1_to_max_ndigits_1(int n)
{
  char *num;
  int i;
  if(n <= 0){
    return;
  }
  num = (char*) malloc(sizeof(char)*(n+1));
  num[n] = '\0';
  for(i = 0 ; i < 10; ++i){
    num[0] = i+'0';
    print_1_to_max_ndigits_recursively(num,n,0);
  }
  free(num);
  
}



int main(void)
{
  char a[] = "000010234";
  print_long_number(a);
  print_1_to_max_ndigits_1(3);
  return 0;
}
