/******************************************************************************
文 件 名    HW07_07
作    者    潘越
班    级	  物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题7.7
截止日期    2017年6月1日

简述：
   本程序为7.2.2程序修改为后进先出链表的程序
******************************************************************************/
#include "stdio.h"
#include "stdlib.h"

struct s_list{ 
    int data; /* 数据域 */
    struct s_list *next; /* 指针域 */ 
} ;

void create_list (struct s_list **headp,int *p);

int main(void)
{
	struct s_list *head=NULL, *p;
	int s[]={1,2,3,4,5,6,7,8,0}; /* 0为结束标记 */
	create_list(&head,s); /* 创建新链表 */
	p=head; /*遍历指针p指向链头 */
	while(p){
		printf("%d\t",p->data); /* 输出数据域的值 */
		p=p->next; /*遍历指针p指向下一结点 */
	}
	printf("\n");
    return 0;
}

void create_list(struct s_list **headp,int *p)
{
	struct s_list * loc_head=NULL,*tail, *t;
	if(p[0]==0) /* 相当于*p==0 */
		;
	else { /* loc_head指向动态分配的第一个结点 */
		tail=(struct s_list *)malloc(sizeof(struct s_list));
		tail->data =*p++; /* 对数据域赋值 */
		tail->next = NULL; /* tail指向第一个结点 */
		while(*p){ /* tail所指结点的指针域指向动态创建的结点 */
            t = (struct s_list *)malloc(sizeof(struct s_list));
            t->data = *p++;
            t->next = tail;
            tail = t;
		}
	}
    *headp = tail;
}