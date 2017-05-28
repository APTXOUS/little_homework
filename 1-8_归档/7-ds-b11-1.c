/*1650254 尤尧寅 计算机一班*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2
#define MAX_NUM_PER_LINE 	10

typedef int Status;
int line_count = 0;   //打印链表时的计数器
/* P.28 形式定义 */
typedef int ElemType;	//可根据需要修改元素的类型

typedef struct LNode {
	ElemType      data;	//存放数据
	struct LNode *next;	//存放直接后继的指针
} LNode, *LinkList;

Status InitList(LinkList *L)
{
	*L = (LNode *)malloc(sizeof(LNode));
	if (*L == NULL)
		exit(OVERFLOW);
	(*L)->next = *L;
	return OK;
}

/* 删除循环链表 */
Status DestroyList(LinkList *L)
{
	LinkList q, p=(*L)->next; //指向首元

						/* 整个链表(含头结点)依次释放 */
	while (p != *L) {    //若链表为空，则循环不执行
		q = p->next; //抓住链表的下一个结点
		free(p);
		p = q;
	}

	*L = NULL;	//头指针置NULL
	return OK;
}



/* 求表的长度 */
int ListLength(LinkList L)
{
	LinkList p = L->next; //指向首元结点
	int len = 0;

	/* 循环整个链表，进行计数 */
	while (p!=L) {
		p = p->next;
		len++;
	}

	return len;
}

/* 在指定位置前插入一个新元素 */
Status ListInsert(LinkList *L, int i, ElemType e)
{
	LinkList s, p;
	p= (*L);	//p指向头结点
	int   pos = 0;

	/* 寻找第i-1个结点 */
	while (p->next!=*L && pos<i - 1) {
		p = p->next;
		pos++;
	}

	if (p==NULL||pos>i - 1)  //i值非法则返回
		return ERROR;

	//执行到此表示找到指定位置，p指向第i-1个结点

	s = (LinkList)malloc(sizeof(LNode));
	if (s == NULL)
		return OVERFLOW;

	s->data = e; 	//新结点数据域赋值
	s->next = p->next;	//新结点的next是第i个
	p->next = s;	//第i-1个的next是新结点

	return OK;
}
/* 删除指定元素，并将被删除元素的值放入e中返回 */
Status ListDelete(LinkList p, ElemType *e)
{
	LinkList q;
	

	q = p->next;       //q指向第i个结点
	p->next = q->next; //第i-1个结点的next域指向第i+1个

	*e = q->data;      //取第i个结点的值
	free(q);           //释放第i个结点

	return OK;
}

Status MyVisit(ElemType e)
{
	printf("%3d->", e);

	/* 每输出MAX_NUM_PER_LINE个，打印一个换行 */
	if ((++line_count) % MAX_NUM_PER_LINE == 0)
		printf("\n");

	return OK;
}
/* 遍历线性表 */
Status ListTraverse(LinkList L, Status(*visit)(ElemType e))
{
	extern int line_count; //在main中定义的打印换行计数器（与算法无关）
	LinkList p = L->next;

	line_count = 0;		//计数器恢复初始值（与算法无关）
	while (p!=L && (*visit)(p->data) == TRUE)
		p = p->next;

	if (p!=L)
		return ERROR;

	printf("\n");//最后打印一个换行，只是为了好看，与算法无关
	return OK;
}

/*循环遍历*/
Status ListTravel(LinkList *L,int k,int m)
{
	LinkList  p;
	p = (*L);	//p指向头结点
	int   pos = 0;

	/* 寻找第i-1个结点 */
	while (pos<m-1) {
		p = p->next;
		if (p == *L)
			p = p->next;
		printf("%d->", p->data);
		pos++;
	}
	printf("\n**************\n");
	pos = 0;
	int num = 1;
	while (ListLength(*L) != 1)
	{
		printf("STEP:%d",num);
		while (pos < k-1)
		{
			if (p->next == *L)
			{
				p = p->next;
			}
			p = p->next;
			//printf("%d->", p->data);
			pos++;
		}
		if (p->next == *L)
			p = p->next;
		int e;
		ListDelete(p, &e);
		printf("\ndelete:%d->\n", e);
		pos = 0;
	//	printf("AFTER LINKLIST:");
		//ListTraverse(*L, MyVisit);
		printf("**************\n\n");
		num++;
	}
	printf("the last person: %d->\n", (*L)->next->data);
	return OK;
}
int main()
{
	int n, m, k;
	printf("请输入n,m,k的值\n");
	scanf("%d%d%d", &n, &m, &k);
	LinkList head;
	InitList(&head);
	for (int i = 1; i <= n; i++)
	{
		ListInsert(&head, i, i);
	}
	ListTravel(&head, k, m);
	DestroyList(&head);
//	system("pause");
	return 0;
}
