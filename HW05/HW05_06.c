/******************************************************************************
�� �� ��    HW05_06
��    ��    ��Խ
��    ��	   ������1601
ѧ    ��    U201614897
��    ��    479773533@qq.com
��    ��    C���Գ������
�� ҵ ��    ϰ��5.6
��ֹ����    2017��5��4��

������
����������n��ѧ����������C���Կγ̵ĳɼ������ɼ����Ӹߵ��͵Ĵ�����������ͬʱ����Ӧ��
������������ѧ����������C���Կγ̵ĳɼ���Ȼ������һ��C���Կγ̳ɼ�ֵ���ö��ֲ��ҽ�
��������������ҵ��иóɼ�������óɼ�ͬѧ��������C���Կγ̵ĳɼ������������ʾ��not 
found!����
******************************************************************************/
#include <stdio.h>
/*����ԭ�ͣ��������ַ���*/
void swap(char a[], char b[], int n);
/*����ԭ�ͣ�ð������*/
void sort(int grades[], char name[][20], int n);
/*����ԭ�ͣ����ֲ���*/
int search(int grades[], int x, int n);

int main(void) {
	int n, i;
	int N;
	/*�������������ֵ��ַ�������*/
	char name[100][20];
	/*����ɼ�������*/
	int grades[100];
	int num[100];
	scanf("%d", &n);
	getchar();
	/*����*/
	for (i = 0; i < n; i++)
		scanf("%s %d", name[i], &grades[i]);
	/*����������*/
	sort(grades, name, n);
	/*���ս�����������˳ɼ�*/
	for(i = 0; i < n; i++)
		printf("%-20s %d\n", name[i], grades[i]);
	printf("\n");
	/*����Ҫ���ҵĳɼ�*/
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &num[i]);
	/*����*/
	for (i = 0; i < N; i++) {
		int index;
		index = search(grades, num[i], n);
		if (index != -1)
			printf("%-20s %d\n", name[index], grades[index]);
		else
			printf("Not found!\n");
	}
	return 0;
}

/********************************************
�������ܣ��������ַ���
���������
		char a[]������a��Ԫ�صĵ�ַ
		char b[]������b��Ԫ�صĵ�ַ
		int n���ַ����ĳ���
�����������
�� �� ֵ����
********************************************/
void swap(char a[], char b[], int n) {
	int i;
	char ch[100];
	for (i = 0; i < n; i++)
		ch[i] = a[i];
	for (i = 0; i < n; i++)
		a[i] = b[i];
	for (i = 0; i < n; i++)
		b[i] = ch[i];
}

/********************************************
�������ܣ�ð������
���������
		int grades[]������grades��Ԫ�صĵ�ַ
		char name[][20]������name��Ԫ�صĵ�ַ
		int n��Ҫ���������
�����������
�� �� ֵ����
********************************************/
void sort(int grades[], char name[][20], int n) {
	int i, j, t;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n -i - 1; j++)
			if (grades[j] < grades[j + 1]) {
				t = grades[j], grades[j] = grades[j + 1], grades[j + 1] = t;
				swap(name[j], name[j + 1], 20);
			}
	}
}

/********************************************
�������ܣ����ֲ���
���������
		int grades[]������grades��Ԫ�صĵ�ַ
		int x��Ҫ���ҵĳɼ�
		int n��Ҫ���ҵ�����
�����������
�� �� ֵ����
********************************************/
int search(int grades[], int x, int n) {
	int front = 0, back = n -1, middle;
	while (front <= back) {
		middle = (front + back) / 2;
		if (x < grades[middle])
			front = middle + 1;
		else if (x > grades[middle])
			back = middle - 1;
		else
			return middle;
	}
	return -1;
}