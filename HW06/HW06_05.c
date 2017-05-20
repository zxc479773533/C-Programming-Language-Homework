/******************************************************************************
文 件 名    HW06_05
作    者    潘越
班    级	  物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题6.5
截止日期    2017年5月18日

简述：
本程序计算a+b并输出结果。设有N位整数和M位小数（N=20，M=10）的数据a,b。
******************************************************************************/
#include <stdio.h>
#include <ctype.h>
#define N 21
#define M 11

/*函数原型：右移位*/
void rightShift(int *a, int n);
/*函数原型：左移位*/
void leftShift(int *a, int n);

int main(void) {
	int x[N], y[N], z[N + 1];
	int a[M], b[M], c[M + 1];
	/*carry用来储存进位*/
	int i, carry = 0, flag;
	/*初始化和数组各位均为零*/
	for (i = 0; i < N + 1; i++)
		*(z + i) = 0;
	for (i = 0; i < M + 1; i++)
		*(c + i) = 0;
	/*输入各数的整数部分和小数部分*/
	i = N - 1;
	while (i >= 0 && isdigit(*(x + i) = getchar()))
		*(x + i--) -= '0';
	if (i >= 0)
		rightShift(x, i);
	i = M - 1;
	while (i >= 0 && isdigit(*(a + i) = getchar()))
		*(a + i--) -= '0';
	if (i >= 0)
		leftShift(a, i);
	i = N - 1;
	while (i >= 0 && isdigit(*(y + i) = getchar()))
		*(y + i--) -= '0';
	if (i >= 0)
		rightShift(y, i);
	i = M - 1;
	while (i >= 0 && isdigit(*(b + i) = getchar()))
		*(b + i--) -= '0';
	if (i >= 0)
		leftShift(b, i);
	/*加法运算：小数部分*/
	for (i = 0; i < M; i++) {
		*(c + i) = *(a + i) + *(b + i) + carry;
		carry = (*(c + i) - *(c + i) % 10) / 10;
		*(c + i) %= 10, *(c + i) += '0';
	}
	/*加法运算：整数部分*/
	for (i = 0; i < N; i++) {
		*(z + i) = *(x + i) + *(y + i) + carry;
		carry = (*(z + i) - *(z + i) % 10) / 10;
		*(z + i) %= 10, *(z + i) += '0';
	}
	/*处理最高位*/
	*(z + N) = carry + '0';
	/*打印结果*/
	flag = 0;
	for (i = N; i >= 0; i--) {
		if ((flag == 0 && *(z + i) != '0') || i == 0)
			flag = 1;
		if (flag == 1)
			putchar(*(z + i));
	}
	putchar('.');
	for (i = M; i >= 0; i--) {
		if (flag == 0 && *(c + i) != '0')
			flag = 1;
		if (flag == 1)
			putchar(*(c + i));
	}
	putchar('\n');
	return 0;
}

/********************************************
函数介绍：右移位
输入参数：
		int *a：指向储存数各位的数组的指针
		int n：该数的长度
输出参数：无
返 回 值：无
********************************************/
void rightShift(int *a, int n) {
	int k, len, sft;
	len = N - 1 - n;
	sft = N - len;
	for (k = 0; k < len; k++)
		*(a + k) = *(a + k + sft);
	for (k = len; k < N; k++)
		*(a + k) = 0;
}

/********************************************
函数介绍：左移位
输入参数：
		int *a：指向储存数各位的数组的指针
		int n：该数的长度
输出参数：无
返 回 值：无
********************************************/
void leftShift(int *a, int n) {
	int k, len, sft;
	len = M - 1 - n;
	sft = M - len;
	for (k = 0; k < sft; k++)
		*(a + k) = 0;
}