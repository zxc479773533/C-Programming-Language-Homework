/******************************************************************************
文 件 名    HW04_04
作    者    潘越
班    级	   物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题4.4
截止日期    2016年4月27日

简述：
本程序将用函数实现求三个数中最大数、计算两数之和
******************************************************************************/
#include <stdio.h>

/*函数原型：求三个数中的最大数*/
int _max(int x, int y, int z);
/*函数原型：求两个数之和*/
float sum(float x, float y);

void main(void)
{
	int a, b, c;
	float d, e;
	printf("Enter three integers:");
	scanf("%d,%d,%d", &a, &b, &c);
	max(a, b, c);
	printf("\nthe maximum of them is %d\n", _max(a, b, c));
	printf("Enter two floating point numbers:");
	scanf("%f,%f", &d, &e);
	sum(d, e);
	printf("\nthe sum of them is  %f\n", sum(d, e));
}

/********************************************
函数介绍：求三个数中的最大数
输入参数：
		int x：x的值
		int y：y的值
		int z：z的值
输出参数：无
返 回 值：int 最大的数的值
********************************************/
int _max(int x, int y, int z)
{
	int t;
	if (x>y)
		t = x;
	else
		t = y;
	if (t<z)
		t = z;
	return t;
}

/********************************************
函数介绍：求两个数的和
输入参数：
	float x：x的值
	float y：y的值
输出参数：无
返 回 值：float x和y的和
********************************************/
float sum(float x, float y)
{
	return x + y;
}