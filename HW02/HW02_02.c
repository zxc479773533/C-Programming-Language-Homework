/******************************************************************************
文 件 名    HW02_02
作    者    潘越
班    级	   物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题2.2
截止日期    2017年4月14日

简述：
本程序将输入的一行字符复制到输出，复制过程中将一个以上的空格字符用一个空格代替。
******************************************************************************/
#include<stdio.h>
/*枚举变量定义*/
enum { COPY, SPACE };

int main(void) {
	int n, i;
	scanf("%d", &n);
	getchar();
	/*主循环*/
	for (i = 1; i <= n; i++) {
		int state = COPY;
		char c;
		while ((c = getchar()) != '\n') {
			switch (state) {
			case COPY:
				/*遇到空格即开始SPACE状态*/
				if (c == ' ') {
					putchar(c);
					state = SPACE;
				}
				else
					putchar(c);
				break;
			case SPACE:
				if (c == ' ')
					/*不输出多余的空格*/
					state = SPACE;
				else {
					putchar(c);
					state = COPY;
				}
				break;
			}
		}
		printf("\n");
	}
	return 0;
}