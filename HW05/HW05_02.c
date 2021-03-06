/******************************************************************************
文 件 名    HW05_02
作    者    潘越
班    级	   物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题5.2
截止日期    2017年5月4日

简述：
本程序用于求解瑟夫问题：M个人围成一圈，从第一个人开始依次从1至N循环报数，每当报数为N时
报数人出圈，直到圈中只剩下一个人为止。
******************************************************************************/
#include <stdio.h>
/*宏定义：一共十个人*/
#define M 10
/*宏定义：从1至3循环报数*/
#define N 3

int main(void) {
    /* 数组a存放圈中人的编号，数组b存放出圈人的编号 */
    int a[M], b[M];
    int i, j, k;
    /* 对圈中人按顺序编号1—M */
    for(i = 0; i < M; i++)
        a[i] = i + 1;
    /* i表示圈中人个数，初始为M个，剩1个人时结束循环；j表示当前报数人的位置 */
    for(i = M, j = 0; i > 1; i--) {
        /* 1至N报数 */
        for(k = 1; k <= N; k++)
            /* 最后一个人报数后第一个人接着报，形成一个圈 */
            if(++j > i - 1) 
                j = 0;
            /* 将报数为N的人的编号存入数组b */
            b[M-i] = j? a[j - 1] : a[M - i];
        if(j)
            /* 压缩数组a，使报数为N的人出圈 */
            for(k = --j; k < i - 1; k++)
                a[k] = a[k + 1];
    }
    /* 按次序输出出圈人的编号 */
    for(i = 0; i < M - 1; i++)
        printf("%6d", b[i]);
    /* 输出圈中最后一个人的编号 */
    printf("%6d\n", a[0]);
    return 0;
}	