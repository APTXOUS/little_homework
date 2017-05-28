/*1650254 尤尧寅 计算机一班*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_NUM_PER_LINE 	10	
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2
typedef int Status;
typedef int ElemType;
typedef struct LNode {
	int      data;	//存放数据
	struct LNode *next;	//存放直接后继的指针
} LNode, *LinkList;
int line_count = 0;   //打印链表时的计数器
					  /***********************测试用函数*********************************/
Status InitList(LinkList *L)
{
	/* 申请头结点空间，赋值给头指针 */
	*L = (LNode *)malloc(sizeof(LNode));
	if (*L == NULL)
		exit(OVERFLOW);

	(*L)->next = NULL;
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
Status ListTraverse(LinkList L, Status(*visit)(ElemType e))
{
	extern int line_count; //在main中定义的打印换行计数器（与算法无关）
	LinkList p = L->next;

	line_count = 0;		//计数器恢复初始值（与算法无关）
	while (p && (*visit)(p->data) == TRUE)
		p = p->next;

	if (p)
		return ERROR;

	printf("\n");//最后打印一个换行，只是为了好看，与算法无关
	return OK;
}

/* 在指定位置前插入一个新元素 */
Status ListInsert(LinkList *L, int i, ElemType e)
{
	LinkList s, p = *L;	//p指向头结点
	int      pos = 0;

	/* 寻找第i-1个结点 */
	while (p && pos<i - 1) {
		p = p->next;
		pos++;
	}

	if (p == NULL || pos>i - 1)  //i值非法则返回
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
/* 删除线性表 */
Status DestroyList(LinkList *L)
{
	LinkList q, p = *L; //指向首元

						/* 整个链表(含头结点)依次释放 */
	while (p) {    //若链表为空，则循环不执行
		q = p->next; //抓住链表的下一个结点
		free(p);
		p = q;
	}

	*L = NULL;	//头指针置NULL
	return OK;
}
//*******************************************************************

void differece(LinkList *La, LinkList *Lb)
{
	LinkList pa = *La, pb = *Lb;
	while (pa->next != NULL)
	{
		pa = pa->next;
	}
	LinkList r;
	r = pa;
	pb = pb->next;
	while (pb)
	{
		pa = *La;
		while (pa->next != NULL&&pa->next->data != pb->data)
		{
			pa = pa->next;
		}
		if (pa->next == NULL)
		{
			LinkList s;
			s = (LinkList)malloc(sizeof(LNode));
			s->data = pb->data;
			s->next = r->next;
			r->next = s;
		}
		else
		{
			LinkList temp_p;
			temp_p = pa->next;
			pa->next = temp_p->next;
			free(temp_p);
		}
		pb = pb->next;
	}

}

int main()
{
	LinkList La;
	LinkList Lb;
	LinkList Lc;
	InitList(&La);
	InitList(&Lb);
	InitList(&Lc);

	for (int i = 12 * 2; i>0; i -= 2)
		ListInsert(&La, 1, i);
	for (int i = 12 * 2; i>0; i -= 3)
		ListInsert(&Lb, 1, i);
	printf("操作前的la和lb\n");
	printf("la:\n");
	ListTraverse(La, MyVisit);
	printf("lb:\n");
	ListTraverse(Lb, MyVisit);
	differece(&La, &Lb);
	printf("操作后的la和lb和l\n");
	printf("la:\n");
	ListTraverse(La, MyVisit);
	printf("lb:\n");
	ListTraverse(Lb, MyVisit);
	DestroyList(&La);
	DestroyList(&Lb);

//	system("pause");
	return 0;
}