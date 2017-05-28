/*1650254 ��Ң�� �����һ��*/
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
	struct DuLNode *next;	//���ֱ�Ӻ�̵�ָ��
	struct DuLNode *prior;  //���ֱ��ǰ�̵�ָ��
} DuLNode, *DuLinkList;
/***************������������*****************/
/* ��ʼ�����Ա� */
Status DuInitList(DuLinkList *L)
{
	*L = (DuLinkList)malloc(sizeof(DuLNode));
	(*L)->next = *L;  //ͷָ��ֱ�Ӹ�NULL
	(*L)->prior = *L;
	return OK;
}

/* ɾ�����Ա� */
Status DestroyList(DuLinkList *L)
{
	DuLinkList q, p = (*L);
	p = p->next;
	/* ��ͷ��㿪ʼ�����ͷţ���ͷ��㣩 */
	while (p != *L) { //������Ϊ�գ���ѭ����ִ��
		q = p->next;  //ץס�������һ�����
		free(p);
		p = q;
	}
	free(*L);
	*L = NULL;
	return OK;
}
Status ListTraverse(DuLinkList L, Status(*visit)(ElemType e))
{
	extern int line_count; //��main�ж���Ĵ�ӡ���м����������㷨�޹أ�
	DuLinkList p = L;
	p = p->next;
	line_count = 0;		//�������ָ���ʼֵ�����㷨�޹أ�
	while (p!=L && (*visit)(p->data) == TRUE)
		p = p->next;

	if (p)
		return ERROR;

	printf("\n");//����ӡһ�����У�ֻ��Ϊ�˺ÿ������㷨�޹�
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

	DuLinkList   p = L->next; //ָ����Ԫ���
	int      len = 0;

	/* ѭ�������������м��� */
	while (p!=L) {
		p = p->next;
		len++;
	}

	return len;

}
Status input_ElemType(ElemType *s)
{
	printf("������ѧ��ѧ�ţ�\n");
	scanf("%d", &(s->num));
	printf("������ѧ��������\n");
	scanf("%s", s->name);
	getchar();
	printf("������ѧ���Ա�\n");
	scanf("%c", &(s->sex));
	printf("������ѧ���ɼ���\n");
	scanf("%f", &(s->score));
	printf("������ѧ��������\n");
	scanf("%s", s->addr);
	getchar();
	return OK;
}
/***************������������*****************/
//****�ڴ�ͷ�ڵ��˫��ѭ������L�е�i��λ��֮ǰ����Ԫ��e************
//****i�ĺϷ�ֵΪ1<=i<=��+1**************************************
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
	ElemType e[] = { { 1001, "����", 'M', 76.5, "�Ϻ���������" },
	{ 1002, "����", 'F', 87, "�Ϻ���������" },
	{ 1003, "����", 'M', 80, "�㽭ʡ������" },
	{ 1004, "����", 'M', 54, "�㽭ʡ������" },
	{ 1005, "ţ��", 'F', 85, "����ʡ�Ͼ���" },
	{ 1006, "���", 'M', 60, "����ʡ������" } };
	DuLinkList L;
	//ElemType e1, e2;
	DuInitList(&L);
	printf("����6��Ԫ�أ�\n");
	for (int i = 0; i<6; i++)
		ListInsert_Dul(&L, ListLength(L) + 1, *(e + i));
	ListTraverse(L, MyVisit);
	printf("��=%d\n\n", ListLength(L));
	
	printf("\n\n��ʾ����Ԫ֮ǰ���룺\n");
	ElemType e1 ;
	input_ElemType(&e1);
	printf("Ҫ�����Ԫ��Ϊ:\n");
	MyVisit(e1);
	ListInsert_Dul(&L, 1, e1);
	printf("����������Ϊ:\n");
	ListTraverse(L, MyVisit);
	printf("��=%d\n\n", ListLength(L));

	printf("\n\n��ʾ��β���ǰ���룺\n");
	ElemType e2;
	input_ElemType(&e2);
	printf("Ҫ�����Ԫ��Ϊ:\n");
	MyVisit(e2);
	ListInsert_Dul(&L,ListLength(L)+1, e2);
	printf("����������Ϊ:\n");
	ListTraverse(L, MyVisit);
	printf("��=%d\n\n", ListLength(L));
	
	int pos;
	printf("������Ҫ�����λ�ã�\n");
	scanf("%d", &pos);
	if(pos<1||pos> ListLength(L)+1)
		printf("����λ�ô���\n");
	else {
		ElemType e3;
		input_ElemType(&e3);
		printf("Ҫ�����Ԫ��Ϊ:\n");
		MyVisit(e3);
		ListInsert_Dul(&L, pos, e3);
		printf("����������Ϊ:\n");
		ListTraverse(L, MyVisit);
		printf("��=%d\n\n", ListLength(L));
	}
	DestroyList(&L);
	return 0;
}