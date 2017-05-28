/*1650254 尤尧寅 计算机一班*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>

#define MAX_NUM_PER_LINE 	10	
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2
int line_count = 0;
typedef int Status;
typedef struct student
{
	int num;
	char name[10];
	char sex;
	float score;
	char addr[30];
}ET, *ElemType;

typedef struct DuLNode {
	ElemType data;
	struct DuLNode *next;	//存放直接后继的指针
	struct DuLNode *prior;  //存放直接前继的指针
} DuLNode, *DuLinkList;
/***************基本函数部分*****************/
/* 初始化线性表 */
Status DuInitList(DuLinkList *L)
{
	*L = (DuLinkList)malloc(sizeof(DuLNode));
	(*L)->next = *L;  //头指针直接赋NULL
	(*L)->prior = *L;
	return OK;
}

/* 删除线性表 */
Status DestroyList(DuLinkList *L)
{
	DuLinkList q, p = (*L);
	p = p->next;
	/* 从头结点开始依次释放（含头结点） */
	while (p != *L) { //若链表为空，则循环不执行
		q = p->next;  //抓住链表的下一个结点
		free(p->data);
		free(p);
		p = q;
	}
	free(*L);
	*L = NULL;
	return OK;
}
Status ListTraverse(DuLinkList L, Status(*visit)(ElemType e))
{
	extern int line_count; //在main中定义的打印换行计数器（与算法无关）
	DuLinkList p = L;
	p = p->prior;
	line_count = 0;		//计数器恢复初始值（与算法无关）
	while (p != L && (*visit)(p->data) == TRUE)
		p = p->prior;

	if (p)
		return ERROR;

	printf("\n");//最后打印一个换行，只是为了好看，与算法无关
	return OK;
}
Status MyVisit(ElemType e)
{
	printf("%d-%s-%c-%f-%s->\n", e->num, e->name, e->sex, e->score, e->addr);
	return OK;
}
DuLinkList GetElemP_Dul(DuLinkList L, int i)
{
	DuLinkList p;
	p = L->next;
	int pos = 1;

	while (p != L&&pos < i) {
		p = p->next;
		pos++;
	}
	if (!p || pos > i)
		return ERROR;

	return p;
}
Status ListLength(DuLinkList L)
{

	DuLinkList   p = L->next; //指向首元结点
	int      len = 0;

	/* 循环整个链表，进行计数 */
	while (p != L) {
		p = p->next;
		len++;
	}

	return len;

}
Status input_ElemType(ElemType s)
{
	printf("请输入学生学号：\n");
	scanf("%d", &(s->num));
	printf("请输入学生姓名：\n");
	scanf("%s", s->name);
	getchar();
	printf("请输入学生性别：\n");
	scanf("%c", &(s->sex));
	printf("请输入学生成绩：\n");
	scanf("%f", &(s->score));
	printf("请输入学生户籍：\n");
	scanf("%s", s->addr);
	getchar();
	return OK;
}
/***************基本函数部分*****************/
//****在带头节点的双链循环链表L中第i个位置之前插入元素e************
//****i的合法值为1<=i<=表长+1**************************************
Status ListInsert_Dul(DuLinkList *L, int i, ElemType e)
{
	DuLinkList p, s;
	if (!(p = GetElemP_Dul(*L, i)))
		return ERROR;
	if (!(s = (DuLinkList)malloc(sizeof(DuLNode))))
		return ERROR;
	s->data = (ElemType)malloc(sizeof(ET));
	if (s->data == NULL)
		return OVERFLOW;
	memcpy(s->data, e, sizeof(ET));
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}
//****删除带头节点的双链循环链表L中第i个元素************
//****i的合法值为1<=i<=表长**************************************
Status ListDelete_Dul(DuLinkList *L, int i, ElemType e)
{
	DuLinkList p;
	if (!(p = GetElemP_Dul(*L, i)))
		return ERROR;
	memcpy(e, p->data, sizeof(ET));

	p->prior->next=p->next;
	p->next->prior = p->prior;
	free(p->data);
	free(p);
	return OK;
}
int main()
{
	ET e[] = { { 1001, "张三", 'M', 76.5, "上海市杨浦区" },
	{ 1002, "李四", 'F', 87, "上海市普陀区" },
	{ 1003, "王五", 'M', 80, "浙江省杭州市" },
	{ 1004, "赵六", 'M', 54, "浙江省绍兴市" },
	{ 1005, "牛七", 'F', 85, "江苏省南京市" },
	{ 1006, "马八", 'M', 60, "江苏省苏州市" } };
	DuLinkList L;
	//ElemType e1, e2;
	DuInitList(&L);
	printf("插入6个元素：\n");
	for (int i = 0; i < 6; i++)
		ListInsert_Dul(&L, ListLength(L) + 1, (e + i));
	ListTraverse(L, MyVisit);
	printf("表长=%d\n\n", ListLength(L));

	ET e1;
	printf("删除首元：\n");
	ListDelete_Dul(&L, 1, &e1);
	ListTraverse(L, MyVisit);
	printf("表长=%d\n\n", ListLength(L));
	printf("删除的元素为：\n");
	MyVisit(&e1);
	printf("\n\n");

	ET e2;
	printf("删除尾结点：\n");
	ListDelete_Dul(&L, ListLength(L), &e2);
	ListTraverse(L, MyVisit);
	printf("表长=%d\n\n", ListLength(L));
	printf("删除的元素为：\n");
	MyVisit(&e2);
	printf("\n\n");


	ET e3;
	printf("请输入要删除的节点位置：\n");
	int pos;
	scanf("%d", &pos);
	ListDelete_Dul(&L, pos, &e3);
	ListTraverse(L, MyVisit);
	printf("表长=%d\n\n", ListLength(L));
	printf("删除的元素为：\n");
	MyVisit(&e3);
	printf("\n\n");


	DestroyList(&L);
//	system("pause");
	return 0;
}