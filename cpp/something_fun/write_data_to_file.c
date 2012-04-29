/*
 * FileName: write_data_to_file.c
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2012-4-30
 * Description: 向文件中直接写入内存信息
 */
#include <stdio.h>

typedef struct Data{
	int i;
	int j;
	float k;
	char a[10];
}Data;

main()
{
	FILE* f = NULL;
	char s[10] = "hello";
	Data a;
	f = fopen("./data.dat","wb");
	if(!f){
		printf("error:file open error!\n");
		exit(1);
	}
	a.i = 1024;
	a.j = -1;
	a.k = 1.0;
	a.a = {1,2,3,4,5,6,7,8,9,0};
	fwrite(&a,1,sizeof(Data),f);
	fclose(f);


}