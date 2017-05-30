/******************************************************************************
文 件 名    HW07_03
作    者    潘越
班    级	  物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题7.3
截止日期    2017年6月1日

简述：
   本程序用单向链表建立一张班级成绩单，包括每个学生的学号、姓名、英语、高等数学、普通物理、C语
   言程序设计四门课程的成绩。用函数编程实现下列功能：
(1) 输入每个学生的各项信息。 
(2) 输出每个学生的各项信息。
(3) 修改指定学生的指定数据项的内容。
(4) 统计每个同学的平均成绩（保留2位小数）。
(5) 输出各位同学的学号、姓名、四门课程的总成绩和平均成绩。
（这里使用改变链表的指针的形式来排序）
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*结构定义：学生*/
typedef struct Student {
    char id[20];
    char name[20];
    float Eng;
    float Math;
    float Phy;
    float C;
    struct Student *next;
    float Sum;
    float Avg;
} stu;

typedef struct {
	stu *head;
	int len;
} LinkList;
/*函数原型*/
void InitList(LinkList *L, int n);
void PrintInf(LinkList *L);
stu* GetPos(LinkList *L, char *id);
void UpdateList(LinkList *L, char *id, char *class, float grade);
void PrintSumAvg(LinkList *L);
void SortLinkList(LinkList *L);
void PrintAvg(LinkList *L);

int main(void) {
    int n;
    scanf("%d", &n);
    getchar();
    LinkList *L;
    InitList(L, n);
    PrintInf(L);
    int m, i;
    scanf("%d", &m);
    getchar();    
    for (i = 0; i < m; i++) {
        char id[100], class[100];
        float grade;
        scanf("%s %s %f", id, class, &grade);
        UpdateList(L, id, class, grade);
    }
    printf("Alter:\n");
    PrintInf(L);
    printf("SumAndAvg:\n");
    PrintSumAvg(L);
    SortLinkList(L);
    printf("Sort:\n");
    PrintAvg(L);
    printf("\n");
    return 0;
}

void InitList(LinkList *L, int n) {
    int i = 0;
    stu *p = (stu *)malloc(sizeof(stu));
    L->head = p;
    L->len = n;
    while(i < n) {
        scanf("%s", p->id);
        scanf("%s", p->name);
        scanf("%f", &p->Eng);
        scanf("%f", &p->Math);
        scanf("%f", &p->Phy);
        scanf("%f", &p->C);
        p->Sum = p->Eng + p->Math + p->Phy + p->C;
        p->Avg = p->Sum / 4;
        if (i < n - 1) {
            stu *q = (stu *)malloc(sizeof(stu));
            p->next = q;
            p = p->next;
        }
        else
            p->next = NULL;
        i++;
    }
}

void PrintInf(LinkList *L) {
    printf("ID             Name                English   Math      Physics   C         \n");
    stu *p = L->head;
    while(p) {
        printf("%-15s", p->id);
        printf("%-20s", p->name);
        printf("%-10.2f", p->Eng);
        printf("%-10.2f", p->Math);
        printf("%-10.2f", p->Phy);
        printf("%-10.2f\n", p->C);
        p = p->next;
    }
    printf("\n");    
}

stu* GetPos(LinkList *L, char *id) {
    stu* p = L->head;
    while(strcmp(p->id,id) != 0)
        p = p->next;
    return p;
}

void UpdateList(LinkList *L, char *id, char *class, float grade) {
    stu *p = GetPos(L, id);
    if (*class == 'E')
        p->Eng = grade;
    else if (*class == 'M')
        p->Math = grade;
    else if (*class == 'P')
        p->Phy = grade;
    else if (*class == 'C')
        p->C = grade;
    stu *a = L->head;
    while(p) {
        p->Sum = p->Eng + p->Math + p->Phy + p->C;
        p->Avg = p->Sum / 4;
        p = p->next;
    }
}

void PrintSumAvg(LinkList *L) {
    printf("ID             Name                SUM       AVG       \n");
    stu *p = L->head;
    while(p) {
        printf("%-15s", p->id);
        printf("%-20s", p->name);
        printf("%-10.2f", p->Sum);
        printf("%-10.2f\n", p->Avg);
        p = p->next;
    }
    printf("\n"); 
}

void SortLinkList(LinkList *L) {
    stu *p1, *piror1, *p2, *piror2, *t;
    p1 = L->head;
    for (p2 = p1->next, piror2 = p1; p2 != NULL; piror2 = p2, p2 = p2->next) {
        if (p1->Avg > p2->Avg) {
            t = p1->next;
            L->head = p2;
            p1->next = p2->next;
            piror2->next = p1;
            p2->next = t;
            p1 = p2;
        }
    }
    for (piror1 = L->head, p1 = piror1->next; p1->next != NULL; piror1 = p1, p1 = p1->next) {     
        for (p2 = p1->next, piror2 = p1; p2 != NULL; piror2 = p2, p2 = p2->next) {
            if (p1->Avg > p2->Avg) {
                t = p2->next;
                piror1->next = p2;
                piror2->next = p1;
                p2->next = p1->next;
                p1->next = t;
                p1 = p2;
            }
        }
    }
}

void PrintAvg(LinkList *L) {
    printf("ID             Name                AVG       \n");
    stu *p = L->head;
    while(p) {
        printf("%-15s", p->id);
        printf("%-20s", p->name);
        printf("%-10.2f\n", p->Avg);
        p = p->next;
    }
    printf("\n");     
}