/******************************************************************************
文 件 名    HW07_04
作    者    潘越
班    级	  物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题7.4
截止日期    2017年6月1日

简述：
   本程序用单向链表建立一张班级成绩单，包括每个学生的学号、姓名、英语、高等数学、普通物理、C语
   言程序设计四门课程的成绩。用函数编程实现下列功能：
(1) 输入每个学生的各项信息。 
(2) 输出每个学生的各项信息。
(3) 修改指定学生的指定数据项的内容。
(4) 统计每个同学的平均成绩（保留2位小数）。
(5) 输出各位同学的学号、姓名、四门课程的总成绩和平均成绩。
（这里使用双向链表）
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
    struct Student *piror;
    struct Student *next;
    float Sum;
    float Avg;
} stu;

typedef struct {
	stu *head, *tail;
	int len;
} LinkList;

/*函数原型*/
void InitList(LinkList **ReportCard);
void PrintInf(LinkList *L);
void UpdateList(LinkList *L);
void SortLinkList(LinkList *L);
void SumAndAvg(LinkList *L);
void swap(stu *a, stu *b);
void SortList(LinkList *L);

int main(void) {
    LinkList *ReportCard = NULL;
    InitList(&ReportCard);
    PrintInf(ReportCard);
    UpdateList(ReportCard);
    SumAndAvg(ReportCard);
    SortList(ReportCard);
    return 0;
}

void InitList(LinkList **ReportCard) {
    int n;
    scanf("%d", &n);
    getchar();
    LinkList *L = (LinkList *)malloc(sizeof(LinkList));
    int i = 1;
    stu *p = (stu *)malloc(sizeof(stu));
    scanf("%s %s %f %f %f %f", p->id, p->name, &p->Eng, &p->Math, &p->Phy, &p->C);
    p->Sum = p->Eng + p->Math + p->Phy + p->C;
    p->Avg = p->Sum / 4;
    p->piror = NULL, p->next = NULL;

    L->head = p, L->tail = p;
    while (i < n) {
        L->tail->next = (stu *)malloc(sizeof(stu));
        L->tail->next->piror = L->tail;
        scanf("%s %s", L->tail->next->id, L->tail->next->name);
        scanf("%f %f %f %f", &L->tail->next->Eng, &L->tail->next->Math, &L->tail->next->Phy, &L->tail->next->C);
        L->tail->next->Sum = L->tail->next->Eng + L->tail->next->Math + L->tail->next->Phy + L->tail->next->C;
        L->tail->next->Avg = L->tail->next->Sum / 4;
        L->tail = L->tail->next;
        L->tail->next = NULL;
        i++;
    }
    *ReportCard = L;
}

void PrintInf(LinkList *L) {
    printf("%-15s%-20s%-10s%-10s%-10s%-10s\n", "ID", "Name", "English", "Math", "Physics", "C");
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

void UpdateList(LinkList *L) {
    int n, i;
    float grade;
    char id[15], course[10];
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++) {
        scanf("%s %s %f", id, course, &grade);
        stu *p = L->head;
        while (p) {
            if (!strcmp(p->id, id))
                break;
            else
                p = p->next;
        }
        if (!strcmp(course, "English"))
            p->Eng = grade;
        else if (!strcmp(course, "Math"))
            p->Math = grade;
        else if (!strcmp(course, "Physics"))
            p->Phy = grade;
        else if (!strcmp(course, "C"))
            p->C = grade;
    }
    printf("Alter:\n");
    PrintInf(L);
}

void SumAndAvg(LinkList *L) {
    printf("SumAndAvg:\n");
    printf("%-15s%-20s%-10s%-10s\n", "ID", "Name", "SUM", "AVG");
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

void swap(stu *a, stu *b) {
    char id[20], name[20];
    float Avg, Sum, Eng, Math, Phy, C;
    strcpy(id, a->id), strcpy(name, a->name);
    Avg = a->Avg, Sum = a->Sum, Eng = a->Eng, Math = a->Math, Phy = a->Phy, C = a->C;
    strcpy(a->id, b->id), strcpy(a->name, b->name);
    a->Avg = b->Avg, a->Sum = b->Sum, a->Eng = b->Eng, a->Math = b->Math, a->Phy = b->Phy, a->C = b->C;
    strcpy(b->id,id), strcpy(b->name, name);
    b->Avg = Avg, b->Sum = Sum, b->Eng = Eng, b->Math = Math, b->Phy = Phy, b->C = C;
}

void SortList(LinkList *L) {
    stu *p, *tail;
    for(p = L->head; p != NULL; p = p->next)
        tail = p;
    while (L->head->next != tail) {
        for (p = L->head; p != tail; p = p->next) {
            if (p->Avg > p->next->Avg) {
                swap(p,p->next);
            }
        }
        tail = p->piror;
    }
    printf("Sort:\n");
    printf("%-15s%-20s%-10s\n", "ID", "Name", "AVG");
    p = L->head;
    while(p) {
        printf("%-15s", p->id);
        printf("%-20s", p->name);
        printf("%-10.2f\n", p->Avg);
        p = p->next;
    }
    printf("\n");
}