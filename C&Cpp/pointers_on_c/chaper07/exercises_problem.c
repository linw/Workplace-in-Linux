/*
 * =====================================================================================
 *
 *       Filename:    exercises_problem.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-5-23 21:23:26
 *       Last Edit:   2012-5-23 21:23:30
 *       Compiler:    gcc
 *       Description: pointers on c chaper7 exercises
 *
 * =====================================================================================
 */
#include <assert.h>
#include <stdarg.h>
#include <limits.h>
// void fun(i,j,k)int i;int j;int k{
//   printf("%d %d %d\n",i,j,k);
// }
// problem1:Hermite Polynomials(厄米多项式)
int hermite(int n, int x)
{
  if(n<=0) return 1;
  if(n==1) return 2*x;
  return 2*x*hermite(n-1,x) - 2*(n-1)*hermite(n-2,x);
}


// problem2: 求a，b的最大公约数
void swap(int *pa, int *pb){
  if(pa == pb) return;
  *pa ^= *pb;
  *pb ^= *pa;
  *pa ^= *pb;
}
int gcd_1(int a, int b)
{
  if(a>b) swap(&a,&b);
  if(b%a == 0) return a;
  else return gcd_1(b%a,a);
}
int gcd_2(int a, int b)
{
  int result;
  if(a>b) swap(&a,&b);
  while(result = b%a){
    b = result;
    if(a>b) swap(&a,&b);
  }
  return a;
}


// problem3: 编写atoi函数
int ascii_to_integer( char *string){
  int i;
  assert(string);
  i = 0;
  while(*string){
    if(*string>='0'&&*string<='9'){
      i = i*10 + *string - '0';
      ++string;
    }
    else 
      return 0;
  }
  return i;
}

// problem4: 编写一个名叫max_list的函数，用于
//           检测任意数目的整型参数并返回它们中的最大值
int max_list(int n,...)
{
  int i;
  int max = INT_MIN;
  int tmp;
  va_list var_arg;
  va_start(var_arg, n);
  for(i = 0; i < n; ++i){
    tmp = va_arg(var_arg,int);
    max = max>tmp?max:tmp;
  }
  va_end(var_arg);
  return max;
}


// problem5: 实现一个简单的printf函数，可以处理%d %f %s %c格式代码
void my_printf(char *s,...)
{
  // int n;
  int i,j;
  int i_value;
  float f_value;
  char c_value;
  char* s_value;
  // n = 0;
  va_list var_arg;
  va_start(var_arg, s);
  for(i = 0; s[i] && s[i+1]; ){
    if(s[i] == '%'
      // &&(s[i+1] == 'd'||
      //    s[i+1] == 'f'||
      //    s[i+1] == 's'||
      //    s[i+1] == 'c')
      ){
      switch(s[i+1]){
        case 'd':
          i_value = va_arg(var_arg,int);
          printf("%d",i_value);
          i += 2;
          break;
        case 'f':
          f_value = va_arg(var_arg,double);
          printf("%f",i_value);
          i += 2;
          break;
        case 's':
          s_value = va_arg(var_arg,int);
          while(*s_value){
            putchar(*s_value);
            ++s_value;
          }
          i += 2;
          break;          
        case 'c':
          c_value = va_arg(var_arg,int);
          putchar(c_value);
          i += 2;
          break;
        default:
          putchar(s[i]);
          ++i;
          break;
      }
    }
    else {
      putchar(s[i]);
      ++i;
    }
  }
  va_end(var_arg);
}


// problem 6: 编写函数用于把数字转化成字符
void written_amount( unsigned int amount, char *buffer )
{
  
}


main()
{
  int i;
  i = hermite(4,2);
  i = gcd_2(15487,7812);
  i = ascii_to_integer("1234");
  i = max_list(5,1,2,3,4,5);
//  printf("%d\n",i);
  my_printf("%d%s",154,"");
}
