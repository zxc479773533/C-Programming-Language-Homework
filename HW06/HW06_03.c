/******************************************************************************
文 件 名    HW06_03
作    者    潘越
班    级	  物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题6.3
截止日期    2017年5月18日

简述：
本程序输入n个整数，排序后输出。排序的原则可由命令行可选参数-d决定，并且有参数-d时按递减顺序排
序，否则按递增顺序排序。要求将排序算法定义成函数，利用指向函数的指针使该函数实现递增或递减排序。
******************************************************************************/
#include <stdio.h>
#include <string.h>

/*函数原型：交换两数*/
void swap(int *x, int *y);
/*函数原型：递增排序*/
void sortup(int *nums, int n);
/*函数原型：递减排序*/
void sortdown(int *nums, int n);

int main(int argc, char const *argv[])
{
	int n, i;
	int nums[100];
	/*将可选参数储存*/
	char ch[] = "-d";
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", nums + i);
	}
	if (argc > 1)
		if (!strcmp(argv[1], ch))
			sortdown(nums, n);
		else
			sortup(nums, n);
	else
		sortup(nums, n);
	for (i = 0; i < n - 1; i++)
		printf("%d ", nums[i]);
	printf("%d\n", nums[n - 1]);
	return 0;
}

/********************************************
函数介绍：交换两数
输入参数：
		int x：数x
		int y：数y
输出参数：无
返 回 值：无
********************************************/
void swap(int *x, int *y) {
	int t;
	t = *x;
	*x = *y;
	*y = t;
}

/********************************************
函数介绍：递增排序
输入参数：
		int *nums：要排序的数字数组的首元素
		int n：数的个数
输出参数：无
返 回 值：无
********************************************/
void sortup(int *nums, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (*(nums + j) < *(nums + j + 1))
				swap(nums + j, nums + j + 1);
}

/********************************************
函数介绍：递减排序
输入参数：
		int *nums：要排序的数字数组的首元素
		int n：数的个数
输出参数：无
返 回 值：无
********************************************/
void sortdown(int *nums, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (*(nums + j) > *(nums + j + 1))
				swap(nums + j, nums + j + 1);
}