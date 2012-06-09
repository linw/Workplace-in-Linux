/*
 * =====================================================================================
 *
 *       Filename:    area_cover.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-5-12 21:54:31
 *       Last Edited: 2012-5-12 21:55:05
 *       Compiler:    gcc
 *       Description: 给定一个区间[x,y](y>=x) 和 N 个无序的目标空间[x1,y1][x2,y2][x3,y3]...
 *                    [xn,yn],判断源区间[x,y]是不是在目标区间内
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
// 区间结构
typedef struct Area{
  int left;
  int right;
}Area;
// solutation1: 简单的方法，利用所有的目标空间减去给定区间
bool is_area_cover_1(Area target, Area *source, unsigned int n){
  int i,j;
  Area tmp;
  tmp = target;
  for(i = 0; i < n; ++i){

}



