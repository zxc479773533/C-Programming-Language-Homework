/******************************************************************************
文 件 名    HW03_02
作    者    潘越
班    级	   物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题3.2
截止日期    2017年4月20日

简述：
本程序证明对于在符号常量BEGIN和END之间的偶数哥德巴赫猜想成立。
******************************************************************************/

#include <stdio.h>

/*函数原型：获取素数表*/
void getPrimes(int n, int *primes);
/*函数原型：打印结果*/
void printAns(int a, int b, int *primes);

int main(void) {
	int begin, end;
	/*储存素数表*/
	int primes[25];
	int i;
	/*获取100以内的素数表*/
	getPrimes(100, primes);
	scanf("%d %d", &begin, &end);
	/*主循环*/
	while (begin != 0) {
		/*调用函数，打印结果*/
		printAns(begin, end, primes);
		/*下一次输入*/
		scanf("%d %d", &begin, &end);
	}
	return 0;
}

/********************************************
函数介绍：打印结果
输入参数：
		int n：数字最大上限
		int *primes：储存素数表的数组首元素的地址
输出参数：无
返 回 值：无
********************************************/
void getPrimes(int n, int *primes) {
	int i, j, k = 0;
	/*flag用来表示i是否有除一和自身以外的因子*/
	int flag;
	for (i = 2; i <= n; i++) {
		flag = 1;
		/*从2一直筛到(i/2)*/
		for (j = 2; j <= (i / 2); j++) {
			if (i % j == 0)
				flag = 0;
		}
		if (flag == 1)
			/*储存该数*/
			primes[k] = i, k++;
	}
}

/********************************************
函数介绍：获取素数表
输入参数：
	int a：BEGIN
	int b：END
	int *primes：储存素数表的数组首元素的地址
输出参数：验证哥德巴赫猜想的等式
返 回 值：无
********************************************/
void printAns(int a, int b, int *primes) {
	int i = 0;
	int m, n;
	/*将i变成比a大的最小的偶数*/
	while (i < a)
		i += 2;
	for (;i <= b; i += 2) {
		int m, n;
		/*flag表示是否已经有满足条件的等式*/
		int flag = 0;
		for (m = 0; m < 25; m++) {
			if (flag == 1)
				continue;
			for (n = m; n < 25; n++) {
				if (flag == 1)
					continue;
				/*当有满足条件的等式时打印结果*/
				if (primes[m] + primes[n] == i) {
					printf("%d=%d+%d\n", i, primes[m], primes[n]);
					flag = 1;
				}
			}
		}
	}
	printf("\n");
}