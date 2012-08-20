/*
 * =====================================================================================
 *
 *       Filename:    test.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-02 17:52:37
 *       Last Edit:   2012-08-10 11:50:46
 *       Compiler:    gcc
 *       Description: something in chaper 12,取样问题
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bigrand()
{
  srand((unsigned)time(NULL));
  // return RAND_MAX*rand() + rand();
  // 原文中使用另一种,但是现在好像不适用,因为现在用的编译器中RAND_MAX = 0x7fffffff,而不是0x7fff
  // 所以会出现溢出问题,下面是一种这种情况下的修改,可以实现同样的功能.
  return 0x7fff*(rand()%0x7fff) + rand()%0x7fff;
}

int randint(int l, int u)
{
  return bigrand()%(u-l+1) + l;
}


// 用于取样的函数,从n个数中选取m个样本
void genknuth(int m, int n)
{
  int i;
  for(i = 0; i < n; ++i){
    if(bigrand()%(n-i) < m){
      printf("%d\n",i);
      --m;
    }
  }
}


void swap(int *a, int *b)
{
  int t;
  if(a == b) return;
  t = *a;
  *a = *b;
  *b = t;
}
// 另一个生成随机数的实现,通过打乱一个有序的子集
// 这种算法适用于m小,n很大的情况
// 复杂度 O(n+mlogm)
int comp(const void *a, const void *b)
{
  return *(int*)a - *(int*)b;
}
void randSwapArray(int m, int n)
{
  int i;
  int j;
  int *a;
  a = (int*) malloc(sizeof(int)*n);
  // 这里其实只需大乱数组的前m个元素,所以可以把代码修改
  /* for(i = 0; i < n; ++i){ */
  /*   swap(a+i,a+randint(i,n-1)); */
  /* } */
  for(i = 0; i < n; ++i){
    a[i] = i;
  }
  for(i = 0; i < m; ++i){
    swap(a+i,a+randint(i,n-1));
  }
  qsort(a,m,sizeof(int),comp);
  for(i = 0; i < m; ++i){
    printf("%d\n",a[i]);
  }
  free(a);
}

/*   上面的方法还可以优化,时间复杂度可以降到O(mlogm)
 *   这种方法通过做一个数组首次访问才赋值的函数可以做到
 *   通过两个辅助向量来实现.下面给出解决方案
 */
void randSwapArray_opt(int m, int n)
{
  int i,j;
  int *a;
  int *from;
  int *to;
  int top;
  top = 0;
  a = (int*) malloc(sizeof(int)*n);
  from = (int*) malloc(sizeof(int)*n);
  to = (int*) malloc(sizeof(int)*2*m);
  for(i = 0; i < 2*m; ++i){
    to[i] = 0;
  }
  for(i = 0; i < m; ++i){
    j = randint(i,n-1);
    if(!(from[i]<top && to[from[i]] == i)){
      from[i] = top;
      to[top] = i;
      a[i] = i;
      ++top;
    }
    if(!(from[j]<top && to[from[j]] == j)){
      from[j] = top;
      to[top] = j;
      a[j] = j;
      ++top;
    }
    swap(a+i,a+j);
  }
  qsort(a,m,sizeof(int),comp);
  for(i = 0; i < m; ++i){
    printf("%d\n",a[i]);
  }
  free(a);
  free(from);
  free(to);
}

//#define _CPP_CODE
// 下面是floyd的一个算法,使得只用m个随机数

#ifdef _CPP_CODE
#include <set>
using std::set;
void genfloyd(int m, int n)
{
  set<int> s;
  set<int>::iterator i;
  for(int j = n-m; j < n; ++j){
    int t = bigrand()%(j+1);
    if(s.find(t) == s.end()){
      s.insert(t);
    }
    else {
      s.insert(j);
    }
  }
  for(i = s.begin(); i != s.end(); ++i){
    printf("%d\n",*i);
  }
}
#endif


int main()
{
  time_t t;
  int i;
  int n = 1000000;
  int m = 0;
  t = clock();
  randSwapArray(m,n);
  randSwapArray_opt(m,n);
#ifdef _CPP_CODE
  genfloyd(m,n);
#endif
  t = clock() - t;
  printf("%f\n",(float)t/CLOCKS_PER_SEC);
  t = clock();
  genknuth(m,n);
  t = clock() - t;
  printf("%f\n",(double)t/CLOCKS_PER_SEC);
  return 0;
}

