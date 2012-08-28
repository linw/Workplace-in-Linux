/*
 * =====================================================================================
 *
 *       Filename:    bitmap_search.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-25 13:56:29
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1024
enum { BITSPERWORD = 32, SHIFT = 5, MASK = 0x1F };
unsigned int bitmap[N];
void set(int i)  { bitmap[i>>SHIFT] |= (1<<(i & MASK));       }
void clr(int i)  { bitmap[i>>SHIFT] &= ~(1<<(i & MASK));      } 
int  test(int i) { return bitmap[i>>SHIFT] & (1<<(i & MASK)); }

main(int argv, char* args[])
{
  int i;
  srand(time(NULL));
  for(i = 0; i < 100; ++i){
    set(rand()%32768);
  }
  for(i = 0; i < N*32; ++i){
    if(test(i)){
      printf("%d find\n",i);
    }
  }
}
