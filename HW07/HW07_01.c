/******************************************************************************
文 件 名    HW07_01
作    者    潘越
班    级	  物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题7.1
截止日期    2017年6月1日

简述：
   本程序设计一个字段结构struct bits，它将一个8位无符号字节从最低位向最高位声明为8个字段，各字
段依次为bit0, bit1, …, bit7，且bit0的优先级最高。同时设计8个函数，第i个函数以biti(i=0,1,2,
…,7)为参数，并且在函数体内输出biti的值。将8个函数的名字存入一个函数指针数组p_fun。如果bit0为1，
调用p_fun[0]指向的函数。如果struct bits中有多位为1，则根据优先级从高到低依次调用函数指针数组
p_fun中相应元素指向的函数。
******************************************************************************/
#include <stdio.h>

struct ISR_BITS {
        unsigned int bit0: 1;
        unsigned int bit1: 1;
        unsigned int bit2: 1;
        unsigned int bit3: 1;
        unsigned int bit4: 1;
        unsigned int bit5: 1;
        unsigned int bit6: 1;
        unsigned int bit7: 1;
        unsigned int rsv : 8;
};

union ISR_REG {
    unsigned short all;
    struct ISR_BITS bit;
};

void (*p_isr[8])(void);

void isr0(void) {
    printf("The Interrupt Service Routine isr0 is called!\n");
}

void isr1(void) {
    printf("The Interrupt Service Routine isr1 is called!\n");
}

void isr2(void) {
    printf("The Interrupt Service Routine isr2 is called!\n");
}

void isr3(void) {
    printf("The Interrupt Service Routine isr3 is called!\n");
}

void isr4(void) {
    printf("The Interrupt Service Routine isr4 is called!\n");
}

void isr5(void) {
    printf("The Interrupt Service Routine isr5 is called!\n");
}

void isr6(void) {
    printf("The Interrupt Service Routine isr6 is called!\n");
}

void isr7(void) {
    printf("The Interrupt Service Routine isr7 is called!\n");
}

int main(void) {
    int N, i;
    int num[100];
    union ISR_REG isr_reg;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &num[i]);
    for (i = 0; i < N; i++) {
        printf("%d:\n", num[i]);
        isr_reg.all = num[i];
        if (isr_reg.bit.bit0)
            isr0();
        if (isr_reg.bit.bit1)
            isr1();
        if (isr_reg.bit.bit2)
            isr2();
        if (isr_reg.bit.bit3)
            isr3();
        if (isr_reg.bit.bit4)
            isr4();
        if (isr_reg.bit.bit5)
            isr5();
        if (isr_reg.bit.bit6)
            isr6();
        if (isr_reg.bit.bit7)
            isr7();
        printf("\n");
    }
    return 0;
}