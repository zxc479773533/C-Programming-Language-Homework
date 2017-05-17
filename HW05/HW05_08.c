/******************************************************************************
文 件 名    HW05_08
作    者    潘越
班    级	   物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题5.8
截止日期    2017年5月4日

简述：
本程序将给出八皇后问题的解。
******************************************************************************/
#include <stdio.h>
/*全局变量：问题的一个解*/
int ways[8], sum = 0;

/*函数原型：求绝对值*/
int abs(int x);
/*函数原型：打印结果*/
void printAns(void);
/*函数原型：判断是否出现矛盾*/
int isConflict(int n);
/*函数原型：递归摆放皇后*/
void getAnsOfEightQueen(int n);

int main(void) {
	getAnsOfEightQueen(0);
	printf("There are %d ways to solve this problem.\n", sum);
	return 0;
}

/********************************************
函数介绍：求绝对值
输入参数：
		int x：要求绝对值的数
输出参数：无
返 回 值：int x的绝对值
********************************************/
int abs(int x) {
	if (x >= 0)
		return x;
	else
		return -x;

}

/********************************************
函数介绍：打印结果
输入参数：无
输出参数：问题的解
返 回 值：无
********************************************/
void printAns(void) {
	int i;
	printf("Ans%d: \n", sum + 1);
	for (i = 0; i < 8; i++)
		printf("(%d,%d)", i + 1, ways[i] + 1);
	printf("\n");
	sum++;
}

/********************************************
函数介绍：判断是否出现矛盾
输入参数：
		int n：已经摆放的皇后个数
输出参数：无
返 回 值：int 是否出现矛盾
********************************************/
int isConflict(int n) {
	int conflict = 0;
	int i;
	for (i = 0; i < n; i++)
		if (ways[i] == ways[n] || abs(ways[i] - ways[n]) == (n - i))
			conflict = 1;
	return conflict;
}

/********************************************
函数介绍：递归摆放皇后
输入参数：
		int n：已经摆放的皇后个数
输出参数：无
返 回 值：无
********************************************/
void getAnsOfEightQueen(int n) {
	int i;
	for (i = 0; i < 8; i++) {
		ways[n] = i;
		/*若不矛盾，则继续摆放*/
		if (!isConflict(n)) {
			/*若摆放完毕，则调用打印函数*/
			if (n == 7)
				printAns();
			else
				getAnsOfEightQueen(n + 1);
		}
	}
}