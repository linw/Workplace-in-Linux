/*
 * =====================================================================================
 *
 *       Filename:    alloc.h
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-4 12:02:23
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 内存分配器实现
 *
 * =====================================================================================
 */
#ifndef _CHAPER11_ALLOC_H
#define _CHAPER11_ALLOC_H
#include <stdlib.h>
#define malloc
#define MALLOC(num,type) (type *) alloc( (num) *sizeof(type))
extern void *alloc(size_t size);
#endif
