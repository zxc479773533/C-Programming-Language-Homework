/******************************************************************************
文 件 名    HW06_01
作    者    潘越
班    级	  物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题6.1
截止日期    2017年5月18日

简述：
本程序从一个长整型变量的高字节开始，依次取出每个字节的高4位和低4位并以数字字符的形式进行显示。
******************************************************************************/
#include <stdio.h>
/*函数原型：打印十六进制*/
void printHex(int a);

int main(void) {
    int N, i, j;
    int nums[100];
    unsigned int bit;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &nums[i]);
    for (i = 0; i < N; i++) {
        /*构造mask为1111*/
        unsigned int mask = 15 << 28;
        for (j = 0; j < 8; j++) {
            /*取出一个字节*/
            bit = *(nums + i) & mask;
            printHex(bit >> (4 * (7 - j)));
            if (j < 7)
                printf(" ");
            mask >>= 4;
        }
        printf("\n");
    }
    return 0;
}

/********************************************
函数介绍：打印十六进制
输入参数：
		int a：十进制数
输出参数：输出该数的十六进制表示
返 回 值：无
********************************************/
void printHex(int a) {
    if (a >= 0 && a <= 9)
        printf("%d", a);
    else if (a < 16)
        printf("%c", 'A' + a - 10);
}