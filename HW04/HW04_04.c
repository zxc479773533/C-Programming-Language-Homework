/******************************************************************************
�� �� ��    HW04_04
��    ��    ��Խ
��    ��	   ������1601
ѧ    ��    U201614897
��    ��    479773533@qq.com
��    ��    C���Գ������
�� ҵ ��    ϰ��4.4
��ֹ����    2016��4��27��

������
�������ú���ʵ���������������������������֮��
******************************************************************************/
#include <stdio.h>

/*����ԭ�ͣ����������е������*/
int _max(int x, int y, int z);
/*����ԭ�ͣ���������֮��*/
float sum(float x, float y);

void main(void)
{
	int a, b, c;
	float d, e;
	printf("Enter three integers:");
	scanf("%d,%d,%d", &a, &b, &c);
	max(a, b, c);
	printf("\nthe maximum of them is %d\n", _max(a, b, c));
	printf("Enter two floating point numbers:");
	scanf("%f,%f", &d, &e);
	sum(d, e);
	printf("\nthe sum of them is  %f\n", sum(d, e));
}

/********************************************
�������ܣ����������е������
���������
		int x��x��ֵ
		int y��y��ֵ
		int z��z��ֵ
�����������
�� �� ֵ��int ��������ֵ
********************************************/
int _max(int x, int y, int z)
{
	int t;
	if (x>y)
		t = x;
	else
		t = y;
	if (t<z)
		t = z;
	return t;
}

/********************************************
�������ܣ����������ĺ�
���������
	float x��x��ֵ
	float y��y��ֵ
�����������
�� �� ֵ��float x��y�ĺ�
********************************************/
float sum(float x, float y)
{
	return x + y;
}