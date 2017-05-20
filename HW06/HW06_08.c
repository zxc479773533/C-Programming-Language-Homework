/******************************************************************************
文 件 名    HW06_08
作    者    潘越
班    级	  物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题6.8
截止日期    2017年5月18日

简述：
本程序通过函数指针和菜单选择来调用字符串拷贝函数或字符串连接函数。
******************************************************************************/
#include "stdio.h"
#include "string.h"
void main(void)
{
    char *(*p)(char *a,const char *b);
    char a[80],b[80],c[160],*result=c;
	int choice,i;
	do{
		printf("\t\t1 copy string.\n");
		printf("\t\t2 connect string.\n");
		printf("\t\t3 exit.\n");
		printf("\t\tinput a number (1-3) please!\n");
		scanf("%d",&choice);
	}while(choice<1 || choice>5);
	switch(choice){
	case 1:
		p=strcpy;
		break;	
	case 2:
		p=strcat;
		break;
	case 3:
		goto down;
	}
	getchar();
	printf("input the first string please!\n");
	i=0;
	do a[i] = getchar();
    while (a[i++] != '\n');
    a[i - 1] = '\0';
	printf("input the second string please!\n");
	i=0;
	do b[i] = getchar();
    while (b[i++] != '\n');
    b[i - 1] = '\0';
	result = (*p)(a,b);
	printf("the result is %s\n",result);
down:
	;
}