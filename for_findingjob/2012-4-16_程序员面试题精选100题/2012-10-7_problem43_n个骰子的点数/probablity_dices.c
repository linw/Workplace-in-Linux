/*
 * =====================================================================================
 *
 *       Filename:    probablity_dices.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-10-07 20:49:19
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_VALUE 6

void print_probability(unsigned int num)
{
  int maxSum = num * MAX_VALUE;
  int *pProbabilities;
  int i;
  int sum;
  if(num == 0){
    return;
  }
  pProbabilities = (int)malloc(maxSum - num + 1);
  for(i = num; i < maxSum; ++i){
    pProbabilities[i] = 0;
  }
  probability(num, pProbabilities);
  sum = 0;
  for(i = num; i <= maxSum; ++i){
    printf("%d\n",pProbabilities[i-num]);
    sum += pProbabilities[i-num];
  }
  printf("%d\n",sum);
  free(pProbabilities);
}

void _probability(unsigned int original, int current, int sum,
		  int *pProbabilities)
{
  int i;
  if(current == 1){
    ++pProbabilities[sum-original];
  }
  else {
    for(i = 1; i <= MAX_VALUE; ++i){
      _probability(original, current-1, sum+i, pProbabilities);
    }
  }
}

void probability(unsigned int num, int* pProbabilities)
{
  int i;
  for(i = 1; i <= MAX_VALUE; ++i){
    _probability(num, num, i, pProbabilities);
  }
}


void print_probability1(int num)
{
  int* pProbabilities[2];
  int i;
  int k;
  int flag;
  if(num<1){
    return;
  }
  pProbabilities[0] = (int*)malloc(MAX_VALUE*num+1);
  pProbabilities[1] = (int*)malloc(MAX_VALUE*num+1);
  for(i = 0; i < MAX_VALUE*num+1; ++i){
    pProbabilities[0][i] = 0;
    pProbabilities[1][i] = 0;
  }
  flag = 0;
  for(i = 1; i <= MAX_VALUE; ++i){
    pProbabilities[flag][i] = 1;
  }
  for(k = 2; k <= num; ++k){
    
  }
}



int
main(void)
{
  print_probability(6);
  return 0;
}
