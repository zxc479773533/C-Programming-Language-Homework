/******************************************************************************
文 件 名    HW06_09
作    者    潘越
班    级	  物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题6.9
截止日期    2017年5月18日

简述：
本程序拷贝数组。
******************************************************************************/
#include "stdio.h"

char *strcpy(char *,char *);

void main(void)
{
    char a[20],b[60]="there is a boat on the lake.";
    printf("%s\n",strcpy(a,b));

}
char *strcpy(char *s,char *t)
{
    char *p = s;
    while(*s++=*t++)
    ;
    return (p);
}