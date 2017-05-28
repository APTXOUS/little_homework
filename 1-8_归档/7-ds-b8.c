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
}ET,ElemType;

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
	p = p->next;
	line_count = 0;		//计数器恢复初始值（与算法无关）
	while (p!=L && (*visit)(p->data) == TRUE)
		p = p->next;

	if (p)
		return ERROR;

	printf("\n");//最后打印一个换行，只是为了好看，与算法无关
	return OK;
}
Status MyVisit(ElemType e)
{
	printf("%d-%s-%c-%f-%s->\n", e.num, e.name, e.sex, e.score, e.addr);
	return OK;
}
DuLinkList GetElemP_Dul(DuLinkList L,int i)
{
	DuLinkList p;
	p= L->next;
	int pos = 1;

	while (p != L&&pos < i){
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
	while (p!=L) {
		p = p->next;
		len++;
	}

	return len;

}
Status input_ElemType(ElemType *s)
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
	DuLinkList p,s;
	if (!(p = GetElemP_Dul(*L, i)))
		return ERROR;
	if (!(s = (DuLinkList)malloc(sizeof(DuLNode))))
		return ERROR;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}
int main()
{
	ElemType e[] = { { 1001, "张三", 'M', 76.5, "上海市杨浦区" },
	{ 1002, "李四", 'F', 87, "上海市普陀区" },
	{ 1003, "王五", 'M', 80, "浙江省杭州市" },
	{ 1004, "赵六", 'M', 54, "浙江省绍兴市" },
	{ 1005, "牛七", 'F', 85, "江苏省南京市" },
	{ 1006, "马八", 'M', 60, "江苏省苏州市" } };
	DuLinkList L;
	//ElemType e1, e2;
	DuInitList(&L);
	printf("插入6个元素：\n");
	for (int i = 0; i<6; i++)
		ListInsert_Dul(&L, ListLength(L) + 1, *(e + i));
	ListTraverse(L, MyVisit);
	printf("表长=%d\n\n", ListLength(L));
	
	printf("\n\n演示在首元之前插入：\n");
	ElemType e1 ;
	input_ElemType(&e1);
	printf("要插入的元素为:\n");
	MyVisit(e1);
	ListInsert_Dul(&L, 1, e1);
	printf("插入后的链表为:\n");
	ListTraverse(L, MyVisit);
	printf("表长=%d\n\n", ListLength(L));

	printf("\n\n演示在尾结点前插入：\n");
	ElemType e2;
	input_ElemType(&e2);
	printf("要插入的元素为:\n");
	MyVisit(e2);
	ListInsert_Dul(&L,ListLength(L)+1, e2);
	printf("插入后的链表为:\n");
	ListTraverse(L, MyVisit);
	printf("表长=%d\n\n", ListLength(L));
	
	int pos;
	printf("请输入要插入的位置：\n");
	scanf("%d", &pos);
	if(pos<1||pos> ListLength(L)+1)
		printf("输入位置错误！\n");
	else {
		ElemType e3;
		input_ElemType(&e3);
		printf("要插入的元素为:\n");
		MyVisit(e3);
		ListInsert_Dul(&L, pos, e3);
		printf("插入后的链表为:\n");
		ListTraverse(L, MyVisit);
		printf("表长=%d\n\n", ListLength(L));
	}
	DestroyList(&L);
	return 0;
}