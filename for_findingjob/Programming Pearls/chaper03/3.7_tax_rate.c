/*
 * =====================================================================================
 *
 *       Filename:    3.7_tax_rate.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-5-4 20:13:16
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */
#include <stdio.h>
double calculate_tax(double income, int base_income, 
                     double increase_income, double base_tax_rate, 
                     double increase_tax_rate)
{
  income = income - base_income;
  double tax = 0;
  int i = 0;
  while(income>increase_income){
    tax += increase_income*(base_tax_rate+i*increase_tax_rate);
    income = income - increase_income;
    ++i;
  }
  tax += income*(base_tax_rate+i*increase_tax_rate);
  return tax;
}


main()
{
  double tax = 0;
  double income = 4200;
  double base_income = 2200;
  double increase_income = 500;
  double base_tax_rate = 0.14;
  double increase_tax_rate = 0.01;
  tax = calculate_tax(income,base_income,increase_income,base_tax_rate,increase_tax_rate);
  printf("%f\n",tax);
}