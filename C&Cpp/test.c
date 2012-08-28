#include <stdio.h>
struct A{
	int i;
	int j;
}A;
main()
{
	int *p;
       struct A a;
	scanf("%d",&p);
	printf("%d",*p);
}
