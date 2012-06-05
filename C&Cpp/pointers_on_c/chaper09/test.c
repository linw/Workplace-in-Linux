#pragma pack(16)
#include <stdio.h>

typedef struct A{
char a;
double b;
int *c;
}A;
main()
{
A k;
printf("%d\n",sizeof(k));
}
