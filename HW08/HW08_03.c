/******************************************************************************
文 件 名    HW08_03
作    者    潘越
班    级    物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题8.3
截止日期    2016年6月8日

简述：
  本程序读取文件内的内容并输出。（使用重定向）
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	char ch;
	FILE *fp;
	if (argc != 2) {
		printf("Arguments error!\n");
		exit(-1);
	}
	if (freopen(argv[1], "r", stdin) == NULL) {
		printf("Can't open %s file!\n", argv[1]);
		exit(-1);
	}
	while ((ch = getchar()) != EOF)
		putchar(ch);
	fclose(fp);
	return 0;
}