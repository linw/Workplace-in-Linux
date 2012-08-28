/*
 * =====================================================================================
 *
 *       Filename:    sparse_matrix.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-7-28 23:03:45
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 存储稀疏矩阵，10.2节中的问题
 *
 * =====================================================================================
 */
#include <stdio.h>
typedef struct SparseMatrix{
  int num[2000];
  int row[2000];
  int col[201];
}SparseMatrix;

main()
{
  int i;
  for(i = 0; i < 100; ++i)
    printf("%d\n",i);
  printf("Hello\n");
}
