/*1650254 ��Ң�� �����һ��*/
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
	int      data;	//�������
	struct LNode *next;	//���ֱ�Ӻ�̵�ָ��
} LNode, *LinkList;
int line_count = 0;   //��ӡ����ʱ�ļ�����
/***********************�����ú���*********************************/
Status InitList(LinkList *L)
{
	*L = NULL;  //ͷָ��ֱ�Ӹ�NULL
	return OK;
}
Status MyVisit(ElemType e)
{

	printf("%3d->", e);
	/* ÿ���MAX_NUM_PER_LINE������ӡһ������ */
	if ((++line_count) % MAX_NUM_PER_LINE == 0)
		printf("\n");

	return OK;
}
Status ListTraverse(LinkList L, Status(*visit)(ElemType e))
{
	extern int line_count; //��main�ж���Ĵ�ӡ���м����������㷨�޹أ�
	LinkList p = L;

	line_count = 0;		//�������ָ���ʼֵ�����㷨�޹أ�
	while (p && (*visit)(p->data) == TRUE)
		p = p->next;

	if (p)
		return ERROR;

	printf("\n");//����ӡһ�����У�ֻ��Ϊ�˺ÿ������㷨�޹�
	return OK;
}

Status ListInsert(LinkList *L, int i, ElemType e)
{
	LinkList s, p = *L;	//pָ��ͷ���
	int      pos = 1;

	if (i != 1) {
		/* Ѱ�ҵ�i-1����� */
		while (p && pos<i - 1) {
			p = p->next;
			pos++;
		}

		if (p == NULL || pos>i - 1)  //iֵ�Ƿ��򷵻�
			return ERROR;
	}

	s = (LinkList)malloc(sizeof(LNode));
	if (s == NULL)
		return OVERFLOW;;

	s->data = e;

	if (i != 1) {
		//����λ�÷���Ԫ����ʱpָ���i-1�����
		s->next = p->next;	//�½���next��p->next
		p->next = s;		//��i-1����next���½��
	}
	else {
		//����λ������Ԫ
		s->next = p;	//��ʱp����L������L=NULL�������
		*L = s;		//ͷָ��ָ���½��
	}

	return OK;
}
/* ɾ�����Ա� */
Status DestroyList(LinkList *L)
{
	LinkList q, p = *L; //ָ����Ԫ

						/* �������������ͷ� */
	while (p) {    //������Ϊ�գ���ѭ����ִ��
		q = p->next; //ץס�������һ�����
		free(p);
		p = q;
	}

	*L = NULL;	//ͷָ����NULL
	return OK;
}
//*******************************************************************

void union_L(LinkList *La, LinkList *Lb)
{
	LinkList p, q, r;
	for (q = (*Lb); q; q = q->next)
	{
		for (p = (*La); p; p=p->next)
			if (p->data == q->data)
				break;
		if (!p)
		{
			r = (LinkList)malloc(sizeof(LNode));
			if (!r)
				exit(OVERFLOW);
			r->data = q->data;
			r->next = (*La)->next;
			(*La)->next = r;
		}
	}
}


int main()
{
	LinkList La;
	LinkList Lb;
	InitList(&La);
	InitList(&Lb);
	for (int i = 12 * 2; i>0; i -= 2)
		ListInsert(&La, 1, i);
	for (int i = 12 * 2; i>0; i -= 3)
		ListInsert(&Lb, 1, i);
	printf("������ǰ��la��lb\n");
	printf("la:\n");
	ListTraverse(La, MyVisit);
	printf("lb:\n");
	ListTraverse(Lb, MyVisit);
	union_L(&La, &Lb);
	printf("������֮���la��lb\n");
	printf("la:\n");
	ListTraverse(La, MyVisit);
	printf("lb:\n");
	ListTraverse(Lb, MyVisit);
	DestroyList(&La);
	DestroyList(&Lb);
//	system("pause");
	return 0;
}