/******************************************************************************
�� �� ��    HW03_03
��    ��    ��Խ
��    ��	   ������1601
ѧ    ��    U201614897
��    ��    479773533@qq.com
��    ��    C���Գ������
�� ҵ ��    ϰ��3.3
��ֹ����    2017��4��20��

������
���������s=1!+2!+3!+��+n!
******************************************************************************/

#include <stdio.h>
#include <Windows.h>

long sum_fac(int n);

int main(void) {
	int k;
	int n;
	scanf("%d", &n);
	for (k = 1; k <= n; k++)
		printf("k = %d\tthe sum is %ld\n", k, sum_fac(k));
	system("pause");
	return 0;
}

long sum_fac(int n) {
	long s = 0;
	int i;
	long fac = 1;
	for (i = 1; i <= n; i++) {
		fac *= i;
		s += fac;
	}
	return s;
}