/*
 * =====================================================================================
 *
 *       Filename:    date_function.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-16 15:09:26
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 给定年份中的某一天,返回该天所在的月份和当月中的日子.1970.1.1 是星期四
 * =====================================================================================
 */
#include <stdio.h>
#include <time.h>
int data[26] = {31,28,31,30,31,30,31,31,30,31,30,31,4,5,6,7,1,2,3};
char* week_str[] = {
  "Monday","Tuesday","Wednesday","Thusday","Friday","Saturday","Sunday"
};
typedef struct Month_week
{
  int month;
  int week;
}Month_week;


Month_week date_function(int year, int day)
{
  int _data[] = {31,28,31,30,31,30,31,31,30,31,30,31,4,5,6,7,1,2,3};
  int i;
  int sum_days;
  int flag;
  Month_week r;
  flag = 0;
  sum_days = 0;
  for(i = 0; i < year-1970; ++i){
    sum_days += 365;
    if(((i+1970)%4 == 0 && (i+1970)%100 !=0) || (i+1970)%400 == 0){
      sum_days += 1;
    }
  }
  if((year%4 == 0 && year%100 !=0) || year%400 == 0){
    flag = 1;
  }
  if(flag) _data[1] = 29;
  for(i = 0 ; day>_data[i] && i < 12; ++i){
    sum_days += _data[i];
    day -= _data[i];
  }
  sum_days += day - 1;
  r.month = i+1;
  r.week = _data[sum_days%7+12];
  return r; 
}

int main(int argv, char* args[])
{
  Month_week r;
  int i,j;
  int sum;
  int year;
  int tmp;
  int days;
  if(argv <= 1) {
    printf("Wrong Use!\n");
    printf("usage: date_function.out <year>\n");
    return 0;
  }
  year = atoi(args[1]);
  printf("%d\n",year);
  i = j = sum = 0;
  days = 1;
  if(((i+1970)%4 == 0 && (i+1970)%100 !=0) || (i+1970)%400 == 0){
    data[1] = 29;
  }
  for(i = 0; i < 12; ++i){
    printf("=============month %2d=============\n",i+1);
    printf("Mon  Tue  Wed  Thu  Fri  Sat  Sun\n");
    r = date_function(year,days);
    sum = 0;
    for(tmp = 1; tmp < r.week; ++tmp,sum++){
      printf("     ");
    }
    for(j = 0; j < data[i]; ++j,++sum,++days){
      if(sum%7 == 0) printf("\n");
      printf("%3d  ",j+1);
    }
    printf("\n\n");
  }
  return 0;
}

