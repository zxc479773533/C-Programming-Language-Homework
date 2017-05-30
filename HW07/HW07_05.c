/******************************************************************************
文 件 名    HW07_05
作    者    潘越
班    级	  物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题7.5
截止日期    2017年6月1日

简述：
   本程序验证7.2.1表达式求值题
******************************************************************************/
#include <stdio.h>

int main(void) {
    char u[] = "UVWXYZ";
    char v[] = "xyz";
    struct T {
        int x;
        char c;
        char *t;
    } a[] = {{11,'A',u}, {100,'B',v}};
    struct T *p = a;
    printf("%d\n", ((++p)->x));
    p = a;
    printf("%c\n", (p++,p->c));
    p = a;
    printf("%c\n", (*p++->t, *p->t));
    p = a;
    printf("%c\n", *(++p)->t);
    p = a;
    printf("%c\n", *++p->t), p->t--;
    p = a;
    printf("%c\n", ++*p->t);
    return 0;
}