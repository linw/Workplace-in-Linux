/*
 * =====================================================================================
 *
 *       Filename:    get_min_num.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-10-07 14:22:58
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NUMBER_LENGTH 10

char strCombine1[2*MAX_NUMBER_LENGTH+1];
char strCombine2[2*MAX_NUMBER_LENGTH+1];

int compare(const void *strNumber1, const void *strNumber2)
{
  strcpy(strCombine1,(char*)strNumber1);
  strcat(strCombine1,(char*)strNumber2);

  strcpy(strCombine2,(char*)strNumber2);
  strcat(strCombine2,(char*)strNumber1);  
  return strcmp(strCombine1, strCombine2);
}

void print_min(int *array, int n)
{
  char (*numStr)[11];
  int i;
  numStr = malloc(sizeof(char)*11*n);
  for(i = 0; i < n; ++i){
    sprintf(numStr[i],"%d",array[i]);
  }
  qsort(numStr, n, sizeof(char)*11, compare);
  /* for(i = 0; i < n; ++i){ */
  /*   printf("%s\n",numStr[i]); */
  /* } */
  for(i = 0; i < n; ++i){
    printf("%s",numStr[i]);
  }
  printf("\n");
  free(numStr);
}

int main()
{
  int a[] = {12,65,234,54};
  print_min(a,4);
  return 0;
}
