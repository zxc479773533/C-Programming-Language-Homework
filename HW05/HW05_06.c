/******************************************************************************
文 件 名    HW05_06
作    者    潘越
班    级	   物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题5.6
截止日期    2017年5月4日

简述：
本程序输入n个学生的姓名和C语言课程的成绩，将成绩按从高到低的次序排序，姓名同时作相应调
整，输出排序后学生的姓名和C语言课程的成绩。然后，输入一个C语言课程成绩值，用二分查找进
行搜索。如果查找到有该成绩，输出该成绩同学的姓名和C语言课程的成绩；否则输出提示“not 
found!”。
******************************************************************************/
#include <stdio.h>
/*函数原型：交换两字符串*/
void swap(char a[], char b[], int n);
/*函数原型：冒泡排序*/
void sort(int grades[], char name[][20], int n);
/*函数原型：二分查找*/
int search(int grades[], int x, int n);

int main(void) {
	int n, i;
	int N;
	/*储存所有人名字的字符串数组*/
	char name[100][20];
	/*储存成绩的数组*/
	int grades[100];
	int num[100];
	scanf("%d", &n);
	getchar();
	/*输入*/
	for (i = 0; i < n; i++)
		scanf("%s %d", name[i], &grades[i]);
	/*调用排序函数*/
	sort(grades, name, n);
	/*按照降序输出所有人成绩*/
	for(i = 0; i < n; i++)
		printf("%-20s %d\n", name[i], grades[i]);
	printf("\n");
	/*输入要查找的成绩*/
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &num[i]);
	/*查找*/
	for (i = 0; i < N; i++) {
		int index;
		index = search(grades, num[i], n);
		if (index != -1)
			printf("%-20s %d\n", name[index], grades[index]);
		else
			printf("Not found!\n");
	}
	return 0;
}

/********************************************
函数介绍：交换两字符串
输入参数：
		char a[]：数组a首元素的地址
		char b[]：数组b首元素的地址
		int n：字符串的长度
输出参数：无
返 回 值：无
********************************************/
void swap(char a[], char b[], int n) {
	int i;
	char ch[100];
	for (i = 0; i < n; i++)
		ch[i] = a[i];
	for (i = 0; i < n; i++)
		a[i] = b[i];
	for (i = 0; i < n; i++)
		b[i] = ch[i];
}

/********************************************
函数介绍：冒泡排序
输入参数：
		int grades[]：数组grades首元素的地址
		char name[][20]：数组name首元素的地址
		int n：要排序的数量
输出参数：无
返 回 值：无
********************************************/
void sort(int grades[], char name[][20], int n) {
	int i, j, t;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n -i - 1; j++)
			if (grades[j] < grades[j + 1]) {
				t = grades[j], grades[j] = grades[j + 1], grades[j + 1] = t;
				swap(name[j], name[j + 1], 20);
			}
	}
}

/********************************************
函数介绍：二分查找
输入参数：
		int grades[]：数组grades首元素的地址
		int x：要查找的成绩
		int n：要查找的数量
输出参数：无
返 回 值：无
********************************************/
int search(int grades[], int x, int n) {
	int front = 0, back = n -1, middle;
	while (front <= back) {
		middle = (front + back) / 2;
		if (x < grades[middle])
			front = middle + 1;
		else if (x > grades[middle])
			back = middle - 1;
		else
			return middle;
	}
	return -1;
}