/******************************************************************************
�� �� ��    HW02_02
��    ��    ��Խ
��    ��	   ������1601
ѧ    ��    U201614897
��    ��    479773533@qq.com
��    ��    C���Գ������
�� ҵ ��    ϰ��2.2
��ֹ����    2017��4��14��

������
�����������һ���ַ����Ƶ���������ƹ����н�һ�����ϵĿո��ַ���һ���ո���档
******************************************************************************/
#include<stdio.h>
/*ö�ٱ�������*/
enum { COPY, SPACE };

int main(void) {
	int n, i;
	scanf("%d", &n);
	getchar();
	/*��ѭ��*/
	for (i = 1; i <= n; i++) {
		int state = COPY;
		char c;
		while ((c = getchar()) != '\n') {
			switch (state) {
			case COPY:
				/*�����ո񼴿�ʼSPACE״̬*/
				if (c == ' ') {
					putchar(c);
					state = SPACE;
				}
				else
					putchar(c);
				break;
			case SPACE:
				if (c == ' ')
					/*���������Ŀո�*/
					state = SPACE;
				else {
					putchar(c);
					state = COPY;
				}
				break;
			}
		}
		printf("\n");
	}
	return 0;
}