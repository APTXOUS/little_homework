/*1650254 尤尧寅 计算机一班*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2


typedef int Status;

/* P.28 形式定义 */
typedef int ElemType;	//可根据需要修改元素的类型

typedef struct LNode {
	ElemType      data;	//存放数据
	struct LNode *next;	//存放直接后继的指针
} LNode, *LinkList;

