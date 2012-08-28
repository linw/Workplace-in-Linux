/*
 * =====================================================================================
 *
 *       Filename:    exercises_problem.c
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-6-3 20:39:15
 *       Last Edit:   2012-6-3 22:30:04
 *       Compiler:    gcc
 *       Description: pointers on c chaper10 exercises
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

// problem 1: 为记账信息编写一个结构体
typedef struct PHONE_NUM{
  short areal;
  short exchange;
  short station;
}PHONE_NUM;
typedef struct LONG_DISTANCE_BILL{
  short month;
  short day;
  short year;
  unsigned long time;
  PHONE_NUM called;
  PHONE_NUM calling;
  PHONE_NUM billed;
}LONG_DISTANCE_BILL;


// problem 2: 为记录汽车销售商的销售情况编写结构体
typedef struct CASH_SELL{
  float suggested_price;
  float sell_price;
  float sale_tax;
  float licens_fee;
}CASH_SELL;

typedef struct LEASE_SELL{
  float suggested_price;
  float sell_price;
  float down_payment;
  float security_deposit;
  float month_payment;
  int lease_term;
}LEASE_SELL;

typedef struct CREDIT_SELL{
  float suggested_price;
  float sell_price;
  float sale_tax;
  float licens_fee;
  float down_payment;
  int loan_duration;
  float interest_rate;
  float month_payment;
  char bank_name[21];
}CREDIT_SELL;
typedef struct BILL_INFO{
  char customer_name[21];
  char customer_address[41];
  char model[21];
  enum{CASH,CREDIT,LEASE} type;
  union{
    CASH_SELL cash_info;
    CREDIT_SELL credit_info;
    LEASE_SELL lease_info;
  }addition_info;
}BILL_INFO;

// problem 3: 
typedef struct MISC{
  unsigned opcode :16;
}MISC;
typedef struct BRANCH{
  unsigned filling :8;
  unsigned opcode :8;
}BRANCH;
typedef struct SGL_OP{
  unsigned filling :3;
  unsigned dst_mode :3;
}SGL_OP;
typedef struct REG_SRC{
  unsigned filling :6;
  unsigned src_reg :3;
}REG_SRC;
typedef struct DBL_OP{
  unsigned filling :12;
  unsigned opcode :4;
}DBL_OP;
typedef union MACHINE_INST{
  unsigned short addr;
  MISC misc;
  BRANCH branch;
  SGL_OP sgl_op;
  REG_SRC reg_src;
  DBL_OP dbl_op;
}MACHINE_INST;


main()
{
  MACHINE_INST x;
  printf("%d\n",sizeof(MACHINE_INST));
  x.addr;
  x.misc.opcode;
  x.branch.opcode;
  x.sgl_op.dst_mode;
  x.reg_src.src_reg;
  x.dbl_op.opcode;
}
