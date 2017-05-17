/******************************************************************************
文 件 名    HW04_02
作    者    潘越
班    级	   物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题4.2
截止日期    2016年4月27日

简述：
本程序将输入一行电报文字，可以任选两种输出：一为原文输出；二为变换字母的大小写（如小写
‘a’变成大写‘A’，大写‘D’变成小写‘d’），其他字符不变。用#define命令控制是否变换字母的大
小写。例如，#define CHANGE 1 则输出变换后的文字，若#define CHANGE 0则原文输出。
******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(void) {
	int n, i;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		int j;
		char ch[100];
		/*获取字符数组*/
		fgets(ch, 100, stdin);
		int CHANGE = ch[0] % 2;
		int len = strlen(ch);
		if (!CHANGE) {
			for (j = 0; j < len; j++)
				putchar(ch[j]);
		}
		else {
			/*转换大小写*/
			for (j = 0; j < len; j++) {
				if (ch[j] >= 'A' && ch[j] <= 'Z')
					putchar(ch[j] + 'a' - 'A');
				else if (ch[j] >= 'a' && ch[j] <= 'z')
					putchar(ch[j] - 'a' + 'A');
				else
					putchar(ch[j]);
			}
		}
	}
	return 0;
}