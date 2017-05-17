/******************************************************************************
文 件 名    HW04_03
作    者    潘越
班    级	   物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题4.3
截止日期    2016年4月27日

简述：
本程序将用宏来计算平方差、交换两数
******************************************************************************/
#include "stdio.h"
#define SUM (a+b)
#define DIF (a-b)
/*用于交换两数*/
#define SWAP(a,b)  t = a, a = b, b = t
void main(void)
{
	int a, b, t;
	printf("Input two integers a, b:");
	/*输入两个待处理的数*/
	scanf("%d,%d", &a, &b);
	/*输出结果*/
	printf("\nSUM=%d\n the difference between square of a and square of b is:%d", SUM, SUM*DIF);
	/*交换两数*/
	SWAP(a, b);
	/*输出结果*/
	printf("\nNow a=%d,b=%d\n", a, b);
}