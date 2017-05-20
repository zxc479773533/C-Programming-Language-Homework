/******************************************************************************
文 件 名    HW06_04
作    者    潘越
班    级	  物联网1601
学    号    U201614897
邮    箱    479773533@qq.com
课    程    C语言程序设计
作 业 号    习题6.4
截止日期    2017年5月18日

简述：
本程序为一共简易的学生成绩处理系统。
******************************************************************************/
#include <stdio.h>
/*N代表课程数*/
#define M 5
/*M代表学生数*/
#define N 5
/*全局变量：储存每门课程的全班总分*/
double classSum[M];
/*函数原型：求每个学生各门课程的平均分*/
void getStuAverage(double *grades, char *stu);
/*函数原型：求每门课程全班的平均分*/
void getClassAverage(double *grades, char *name);
/*函数原型：求出每门课程低于平均成绩的人数*/
void getNumOfLows(double *grades, char *name);
/*函数原型：求出每门课程不及格的人数和90分以上的人数*/
void getNumOffailersAndTops(double *grades, char *name);

int main(void) {
    int i, j;
    /*name数组储存每门课程的名称*/
    char name[M][10];
    /*stu数组储存每个学生的名字*/
    char stu[N][10];
    /*grades数组储存全班每个人每门课程的分数*/
    double grades[N][M];
    /*输入*/
    for (i = 0; i < M; i++)
        scanf("%s", *(name + i));
    getchar();
    for (i = 0; i < N; i++) {
        scanf("%s", *(stu + i));
        for (j = 0; j < M; j++)
            scanf("%lf", *(grades + i) + j);
    }
    /*函数调用*/
    getStuAverage(*grades, *stu);
    getClassAverage(*grades, *name);
    getNumOfLows(*grades, *name);
    getNumOffailersAndTops(*grades, *name);
    return 0;
}

/********************************************
函数介绍：求每个学生各门课程的平均分
输入参数：
		double *grades：指向成绩数组的指针
		char *stu：指向每个学生名字数组的指针
输出参数：每个学生各门课程的平均分
返 回 值：无
********************************************/
void getStuAverage(double *grades, char *stu) {
    int i, j;
    double sum[N];
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            *(sum + i) += *(grades + i * N + j);
        }
        printf("Average score of %s is %.2lf\n", stu + i * 10, *(sum + i) / N);
    }
}

/********************************************
函数介绍：求每门课程全班的平均分
输入参数：
		double *grades：指向成绩数组的指针
		char *name：指向每门课程名称数组的指针
输出参数：每门课程全班的平均分
返 回 值：无
********************************************/
void getClassAverage(double *grades, char *name) {
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            *(classSum + i) += *(grades + j * N + i);
        }
        printf("Average score of %s is %.2lf\n", name + i * 10, *(classSum + i) / M);
    }
}

/********************************************
函数介绍：求出每门课程低于平均成绩的人数
输入参数：
		double *grades：指向成绩数组的指针
		char *name：指向每门课程名称数组的指针
输出参数：每门课程低于平均成绩的人数
返 回 值：无
********************************************/
void getNumOfLows(double *grades, char *name) {
    int i, j;
    int lows[M] = {0, 0, 0, 0, 0};
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (*(grades + j * N + i) < *(classSum + i) / N)
                *(lows + i) += 1;
        }
    }
    for (i = 0; i < M; i++) {
        printf("Number of students lower than avg of %s is %d\n", name + i * 10, *(lows + i));
    }
}

/********************************************
函数介绍：求出每门课程不及格的人数和90分以上的人数
输入参数：
		double *grades：指向成绩数组的指针
		char *name：指向每门课程名称数组的指针
输出参数：每门课程不及格的人数和90分以上的人数
返 回 值：无
********************************************/
void getNumOffailersAndTops(double *grades, char *name) {
    int i, j;
    int fails[M] = {0, 0, 0, 0, 0};
    int tops[M] = {0, 0, 0, 0, 0};
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (*(grades + j * N + i) < 60)
                *(fails + i) += 1;
            if (*(grades + j * N + i) >= 90)
                *(tops + i) += 1;
        }
    }
    for (i = 0; i < M; i++) {
        printf("Number of students %s fail is %d\n", name + i * 10, *(fails + i));
    }
    for (i = 0; i < M; i++) {
        printf("Number of students %s perfect is %d\n", name + i * 10, *(tops + i));
    }
}