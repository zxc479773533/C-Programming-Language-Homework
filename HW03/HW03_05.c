/******************************************************************************
文 件 名    HW03_05
作    者    潘越
班    级	   物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题3.5
截止日期    2017年4月20日

简述：
本程序计算s=1/1!+1/2!+1/3!+…+1/n!
******************************************************************************/
#include <stdio.h>

double sum_fac(int n);

int main(void) {
	int k;
	double n;
	scanf("%lf", &n);
	for (k = 1; k <= n; k++)
		printf("k = %d\tthe sum is %lf\n", k, sum_fac(k));
	return 0;
}

double sum_fac(int n) {
	double s = 1;
	double i;
	for (i = n; i >= 1; i--) {
		s = s / i + 1;
	}
	return s - 1;
}