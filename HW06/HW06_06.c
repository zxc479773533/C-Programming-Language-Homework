/******************************************************************************
文 件 名    HW06_06
作    者    潘越
班    级	  物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题6.6
截止日期    2017年5月18日

简述：
编写使用复杂声明char *(*p[2])(const char *,const char *);的程序。
******************************************************************************/
#include <stdio.h>
#include <string.h>

char *minstr(const char *a, const char *b);
char *maxstr(const char *a, const char *b);

int main(void) {
	char *(*p[2])(const char *a, const char *b);
	char a[100], b[100], c[2][100], *d[2];
	int i;
	for (i = 0; i < 2; i++)
		d[i] = c[i];
	p[0] = minstr;
	p[1] = maxstr;
	printf("Please input the first string.\n");
	i = 0;
	do a[i] = getchar();
    while (a[i++] != '\n');
    	a[i - 1] = '\0';
	printf("Please input the second string.\n");
	i = 0;
	do b[i] = getchar();
    while (b[i++] != '\n');
    	b[i - 1] = '\0';
    for (i = 0; i < 2; i++)
		d[i] = (*(p+i))(a,b);
	for (i = 0; i < 2; i++)
		printf("the result%d is %s\n", i, *(d + i));
	return 0;
}

char *minstr(const char *a, const char *b) {
	char *x = a;
	char *y = b;
	if (strcmp(a, b) >= 0)
		return y;
	else
		return x;
}

char *maxstr(const char *a, const char *b) {
	char *x = a;
	char *y = b;
	if (strcmp(a, b) >= 0)
		return x;
	else
		return y;
}