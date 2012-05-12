/*
 * FileName: write_data_to_file.c
 * Author: linwei
 * E-mail: kinglw8729@gmail.com
 * Date: 2012-4-30
 * Description: 向文件中直接写入内存信息
 */
#include "stdio.h"
#include "string.h"

typedef struct Data{
    int i;
    int j;
    float k;
    char a[10];
}Data;


void write_data_to_file(const char* fname){
    FILE* f = NULL;
    char s[10] = "hello";
    Data a[2];

    f = fopen(fname,"wb");
    if(!f){
        printf("error:file open error!\n");
        exit(1);
    }
    a[0].i = 1024;
    a[0].j = -1;
    a[0].k = 1.0;
    strcpy(a[0].a,s);
    a[1].i = 1000;
    a[1].j = -5;
    a[1].k = 1.15;
    strcpy(a[1].a,s);

    // printf("%d\n", i);
    // printf("%s\n", a.a);
    fwrite(a,sizeof(Data),2,f);
    fclose(f);    
}

void read_data_from_file(const char* fname){ 
    FILE* f = NULL;
    Data a;
    f = fopen(fname,"rb");
    fseek(f,sizeof(Data),SEEK_SET);
    fread(&a,sizeof(Data),1,f);
    printf("%d\n", a.i);
    printf("%d\n", a.j);
    printf("%f\n", a.k);
    printf("%s\n", a.a);
    fclose(f);
}


main()
{
    write_data_to_file("data.dat");
    read_data_from_file("data.dat");
}
