/******************************************************************************
文 件 名    HW08_04
作    者    潘越
班    级    物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题8.4
截止日期    2016年6月8日

简述：
  本程序从键盘输入一行英文句子，将每个单词的首字母换成大写字母，然后输出到一个磁盘文件
  “test”中保存。
******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(void) {
	char ch[100];
	fgets(ch, 100, stdin);
	int i = 0, flag = 1;
	while (i < strlen(ch)) {
		if (flag == 1) {
			if (ch[i] > 'a' && ch[i] < 'z')
				ch[i] = ch[i] - ('a' - 'A');
			flag = 0;
		}
		if (ch[i] == ' ' && ch[i+1] != ' ')
			flag = 1;
		i++;
	}
	FILE *fp;
	fp = fopen("E:\\test.txt", "a");
	fwrite(ch, sizeof(char) * strlen(ch), 1, fp);
	fclose(fp);
	return 0;
}