/******************************************************************************
�� �� ��    HW04_05
��    ��    ��Խ
��    ��	   ������1601
ѧ    ��    U201614897
��    ��    479773533@qq.com
��    ��    C���Գ������
�� ҵ ��    ϰ��4.5
��ֹ����    2016��4��27��

������
�������ú���ʵ���������������������������֮��
******************************************************************************/
#include <stdio.h>

/*�������������е�������Ĵ����*/
#define max(x,y,z)    int t;if (x>y)t=x;else t=y;if (t<z)t=z;

/*����ԭ�ͣ���������֮��*/
float sum(float x, float y);

void main(void)
{
	int a, b, c;
	float d, e;
	printf("Enter three integers:");
	scanf("%d,%d,%d", &a, &b, &c);
	max(a, b, c);
	printf("\nthe maximum of them is %d\n", t);
	printf("Enter two floating point numbers:");
	scanf("%f,%f", &d, &e);
	sum(d, e);
	printf("\nthe sum of them is  %f\n", sum(d, e));
}

/********************************************
�������ܣ���������֮��
���������
	float x��x��ֵ
	float y��y��ֵ
�����������
�� �� ֵ��float ������֮��
********************************************/
float sum(float x, float y)
{
	return x + y;
}