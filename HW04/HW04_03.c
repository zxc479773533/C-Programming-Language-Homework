/******************************************************************************
�� �� ��    HW04_03
��    ��    ��Խ
��    ��	   ������1601
ѧ    ��    U201614897
��    ��    479773533@qq.com
��    ��    C���Գ������
�� ҵ ��    ϰ��4.3
��ֹ����    2016��4��27��

������
�������ú�������ƽ�����������
******************************************************************************/
#include "stdio.h"
#define SUM (a+b)
#define DIF (a-b)
/*���ڽ�������*/
#define SWAP(a,b)  t = a, a = b, b = t
void main(void)
{
	int a, b, t;
	printf("Input two integers a, b:");
	/*�����������������*/
	scanf("%d,%d", &a, &b);
	/*������*/
	printf("\nSUM=%d\n the difference between square of a and square of b is:%d", SUM, SUM*DIF);
	/*��������*/
	SWAP(a, b);
	/*������*/
	printf("\nNow a=%d,b=%d\n", a, b);
}