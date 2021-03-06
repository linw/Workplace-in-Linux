/*
 * =====================================================================================
 *
 *       Filename:    exercises_problem.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-6 21:54:42
 *       Last Edit:
 *       Compiler:    gcc
 *       Description: exercises in chaper13
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
// problem 1: 统计输入的字符中不同种所占百分比，不可以使用if语句
// 使用函数跳转表
int is_not_print(char ch)
{
  return !isprint(ch);
}
void com_pre()
{
  int (*f[7])(int) = {
    iscntrl,
    isspace,
    isdigit,
    islower,
    isupper,
    ispunct,
    is_not_print};
  char s[7][10] ={
    "cntrl",
    "space",
    "digit",
    "lower",
    "upper",
    "punct",
    "notprint"};
  int count[7] = {0};
  int all = 0;
  char c;
  int i;
  i = 0;
  while((c=getchar())!='\n'){
    ++all;
    for(i = 0; i < 7; ++i){
      count[i] += (f[i](c)?1:0);
      //    if(f[i](c)) printf("%s\n",s[i]);
    }
  }
  for(i = 0; i < 7; ++i)
    printf("%s:%f\n",s[i],(double)count[i]/all);
}


// problem 2: 写一个遍历单链表的函数
typedef struct NODE{
  struct NODE *next;
  int elem;
}NODE;

void travel_list(NODE *root, int (*f)(NODE*))
{
  while(root){
    f(root);
    root = root->next;
  }
}


// problem 3: 转化代码，替换switch为跳转表
/*
 * 可以定义一些函数，然后放到跳转表中，这些函数要拥有相同的接口
 */


// problem 4: 编写一个sort函数
void switch_mem(void *a, void *b, size_t size)
{
  unsigned char *p1;
  unsigned char *p2;
  int i;
  p1 = a;
  p2 = b;
  i = 0;
  if(p1 == p2) return;
  for(i = 0; i < size; ++i){
    p1[i] ^= p2[i];
    p2[i] ^= p1[i];
    p1[i] ^= p2[i];
  }  
}

void sort(void * base, size_t num, size_t size, 
	 int ( * comparator ) ( const void *, const void * ))
{
  int i,j;
  if(base == NULL){
    printf("Null addtress!\n");
    exit(-1);
  }
  for(i = 0; i < num; ++i){
    for(j = i+1; j < num; ++j){
      if(comparator(base+i*size,base+j*size)>0){
	switch_mem(base+i*size,base+j*size,size);
      }
    }
  }
}

int comparator(const void *a, const void *b)
{
  return *((int*)a) - *((int*)b);
}


// problem 5: 命令行处理
char **
do_args( int argc, char **argv, char *control,
	 void (*do_arg)( int ch, char *value ),
	 void (*illegal_arg)( int ch) )
{

}



main()
{
  int a[10] = {0,9,8,7,6,5,4,3,2,1};
  int i;
  com_pre();
  sort(a,10,sizeof(int),comparator);
  for(i = 0; i < 10; ++i)
    printf("%d ",a[i]);
}
