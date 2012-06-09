/*
 * =====================================================================================
 *
 *       Filename:    find_the_number.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-5-14 14:57:19
 *       Last Edit:   2012-5-14 14:57:19
 *       Compiler:    gcc
 *       Description:
 *                  题目：1.这个程序要找的是符合什么条件的数
 *                       2.这样的数存在吗？符合这一条件的最小的数是什么？4
 *                       3.在电脑上运行这一程序，你估计多长时间才能输出第一个结果？时间精确到分钟
 *                         （电脑：单核CPU 2.0GHz，内存和硬盘等资源充足
 *
 *                  解答：该程序找rg【】中数的倍数的数，且是rg中两个相邻数的倍数
 * =====================================================================================
 */
#include <stdio.h>
#include <limits.h>
#include <time.h>
main()
{
  int rg[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,
              18,19,20,21,22,23,24,25,26,27,28,29,30,31};
  int i,j;
  int hit;
  int hit1;
  int hit2;
  int max_int = ~(1<<31);
  time_t start;
  time_t end;
  start = clock();
  for(i = 1; i <INT_MAX; ++i){
    hit = 0;
    hit1 = -1;
    hit2 = -1;
    for(j = 0; (j<30)&&(hit<=2);++j){
      if((i%rg[j]) != 0){
          hit++;
          if(hit == 1)
            hit1 = j;
          else if(hit == 2)
            hit2 = j;
          else break;
      }
    }
    if((hit == 2) && (hit1+1 == hit2))
        printf("found %d",i);
  }
  end = clock();
  printf("%nd\n",(start-end)/1000);
}
