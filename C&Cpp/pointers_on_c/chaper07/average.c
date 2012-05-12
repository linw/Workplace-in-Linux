/*
 * =====================================================================================
 *
 *       Filename:    average.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-5-3 10:56:25
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
// #include <stdio.h>
#include <stdarg.h>
float average(int n_values,...){
    va_list arg_ptr;
    int count;
    float sum = 0;
    va_start(arg_ptr, n_values);
    for(count = 0; count < n_values; ++count){
        sum += va_arg(arg_ptr,int);
        // sum = sum + va_arg(arg_ptr, int);
    }
    va_end(arg_ptr);
    return sum/n_values;
}


// int SqSum(int n1, ...)

// {

// va_list arg_ptr;

// int nSqSum = 0, n = n1;

// va_start(arg_ptr, n1);

// while (n > 0)

// {

//     nSqSum += (n * n);

//     n = va_arg(arg_ptr, int);

// }

// va_end(arg_ptr);

// return nSqSum;

// }
main()
{
    
}
// main()
// {
//     float res = average(9,2,3,4,5,6,7,8,9,10);
//     printf("%f\n", res);
//     // int nSqSum = SqSum(7, 2, 7, 11, -1);
//     // printf("%d\n", nSqSum);
// }
