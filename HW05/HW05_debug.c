/******************************************************************************
�� �� ��    HW05_debug
��    ��    ��Խ
��    ��	   ������1601
ѧ    ��    U201614897
��    ��    479773533@qq.com
��    ��    C���Գ������
�� ҵ ��    ϰ��5.debug
��ֹ����    2017��5��4��

������
�������ַ�����t��ǰn���ַ����ӵ��ַ�����s���ַ�����β����
******************************************************************************/
#include <stdio.h>
/*����ԭ�ͣ����ַ�����t��ǰn���ַ����ӵ��ַ�����s���ַ�����β��*/
void _strncat(char [], char [], int);

int main(void) {
    char a[50]="The adopted symbol is ",b[27]="abcdefghijklmnopqrstuvwxyz";
    _strncat(a, b, 4);
	printf("%s\n",a);
    return 0;
}

/********************************************
�������ܣ����ַ�����t��ǰn���ַ����ӵ��ַ�����s���ַ�����β��
���������
		char s[]������s��Ԫ�صĵ�ַ
		char t[]������t��Ԫ�صĵ�ַ
�����������
�� �� ֵ����
********************************************/
void _strncat(char s[],char t[], int n) {
    int i = 0, j;
	/*����sǰ�����е�Ԫ��*/
	while(s[i] != '\0')
		i++; 
	for(j = 0; j < n && t[j];)
		s[i++] = t[j++];
      	s[i] = '\0';
}