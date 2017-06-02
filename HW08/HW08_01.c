/******************************************************************************
文 件 名    HW08_01
作    者    潘越
班    级    物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题8.1
截止日期    2016年6月8日

简述：
  本程序验证实验题8.2.1
******************************************************************************/
#include <stdio.h>

int main(void) {
    short a = 0x253f, b = 0x7b7d;
    char ch;
    FILE *fp1, *fp2;
    fp1 = fopen("D:\\abc1.bin", "wb+");
    fp2 = fopen("D:\\abc2.txt", "w+");
    fwrite(&a, sizeof(short), 1, fp1);
    fwrite(&b, sizeof(short), 1, fp1);
    fprintf(fp2, "%hx %hx", a, b);
    rewind(fp1);rewind(fp2);
    while ((ch = fgetc(fp1)) != EOF)
        putchar(ch);
    putchar('\n');
    while ((ch = fgetc(fp2)) != EOF)
        putchar(ch);
    putchar('\n');
    fclose(fp1);
    fclose(fp2);
    return 0;
}