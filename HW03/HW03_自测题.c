/******************************************************************************
文 件 名    HW03_自设题
作    者    潘越
班    级	   物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题3.自测题
截止日期    2017年4月20日

简述：
本程序用逆序数定义来计算六阶以内行列式的值，并输出
******************************************************************************/

#include <stdio.h>
#include <windows.h>
#include <math.h>

/*定义全局变量sum,用以储存行列式的值*/
int sum = 0;

/*函数原型：移动光标*/
void goto_xy(int x, int y);
/*函数原型：计算行列式求和中每一项的符号*/
int getp(int *p, int n);
/*函数原型：计算行列式的值*/
void getA(int *matrix, int * p, int counter, int n);//计算行列式的值

int main(void) {
	/*定义n表示矩阵的阶数*/
	int n;
	int i, j;
	/*定义一个6*6的二维数组储存矩阵*/
	int matrix[6][6];
	/*定义一个长度为6的数组，分别储存从矩阵每一行取出的一个数*/
	int p[6];
	/*输入矩阵的阶数*/
	printf("请选择您要计算的矩阵阶数（2~6）: ");
	scanf_s("%d", &n);
	/*输入矩阵*/
	printf("\n请输入您要计算的矩阵A");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			/*控制光标的位置*/
			goto_xy(j * 4 + 1, 4 + i * 2);
			scanf_s("%d", &matrix[i][j]);
		}
	}
	printf("\n");
	/*调用函数getA，得出行列式的值*/
	getA(matrix, p, 0, n);
	/*输出*/
	printf("以矩阵A中的元素构成的行列式的值是： ");
	printf("%d\n", sum);
	system("pause");
	return 0;
}

/********************************************
函数介绍：移动光标
输入参数：
		int x：第x行
		int y：第y列
输出参数：无
返 回 值：无
********************************************/
void goto_xy(int x, int y) {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x,y };
	SetConsoleCursorPosition(hOut, pos);
}

/********************************************
函数介绍：计算行列式求和中每一项的符号
输入参数：
		int *p：数组p首元素的地址
		int  n：矩阵的阶数
输出参数：无
返 回 值：int 符号+1或者-1
********************************************/
int getp(int *p, int n) {
	int i, j, k = 0;
	/*计算逆序数*/
	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			/*逆序数的定义：当某两个元素的先后次序与标准次序(1~n)不同时，就说有1个逆序。*/
			if (p[j] > p[i])
				k++;
		}
	}
	/*计算(-1)^k，其中k为逆序数*/
	if ((k % 2) == 0)
		return 1;
	else
		return -1;
}

/********************************************
函数介绍：计算行列式的值
输入参数：
	int *matrix：数组matrix首元素的地址
	int *p：数组P首元素的地址
	int counter:计数器，用以判断是否停止迭代
	int n:矩阵的阶数
输出参数：无
返 回 值：无
********************************************/
void getA(int *matrix, int *p, int counter, int n) {
	int i, j;
	/*当*/
	if (counter == n) {
		int ans = 1;
		/*根据序号的排列，计算出矩阵中对应项的乘积*/
		for (i = 0; i < n; i++)
			ans *= *(matrix + i * 6 + p[i] - 1);
		/*判断每组乘积的符号，并相加*/
		sum += ans * getp(p, n);
	}
	else {
		/*递归法导出1~n的全排列*/
		for (i = 1; i <= n; i++) {
			int ok = 1;
			for (j = 0; j < counter && ok; j++) {
				/*检测数i是否出现*/
				if (p[j] == i)
					ok = 0;
			}
			if (ok) {
				/*对数的排列赋值*/
				p[counter] = i;
				/*递归调用*/
				getA(matrix, p, counter + 1, n, 6);
			}
		}
	}
}