/*
 * =====================================================================================
 *
 *       Filename:    exercises_problem.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-4 14:13:55
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: exercises problem in chaper11
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// problem 1: ʵ��calloc����,�ڲ�ʹ��malloc
void *my_calloc( size_t num_elements, size_t element_size)
{
  size_t size;
  char *p;
  int n;
  size = num_elements*element_size;
  p = malloc(size);
  if(p == NULL){
    printf("Out of memory!\n");
    exit(-1);
  }
  while(size)
    p[size--] = 0;
  return p;  
}


// problem 2: ����һϵ���������ö�̬�������������������
// �����û���Ѷȣ�������

// problem 3: ��ȡһ���ַ�����Ȼ���Ƶ���̬������ڴ���
// ��Ҫʹ����realloc() ��������������ʵ�ֲ�ȷ����С�Ķ�̬���䣬
// Ҳ����ÿ�ζ����һ�����ڴ棬ֻ�е�������ʱ�ٷ����ڴ�
void get_and_store_str()
{
  char *p;
  char c;
  int i;
  p = NULL;
  i = 0;
  while((c = getchar()) != '\n'){
    p = realloc(p,(i+1)*sizeof(char));
    if(p == NULL){
      printf("Out of memory!\n");
      exit(-1);
    }
    p[i] = c;
    ++i;
  }
  p[i] = 0;
  printf("%s\n",p);
  free(p);
}


// problem 4: ����һ������ṹ
// �ܼ򵥣�������



main()
{
  int *p;
  int i;
  /* p = my_calloc(10,sizeof(int)); */
  p = malloc(10*sizeof(int));
  for(i = 0; i < 10; ++i)
    printf("%d ",p[i]);
  free(p);
  get_and_store_str();
}
