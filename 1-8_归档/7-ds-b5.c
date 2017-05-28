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

void MergeList_L(LinkList *La, LinkList *Lb,LinkList *Lc)
{
	LinkList pa=(*La), pb=(*Lb), pc;
	if (pa->data < pb->data) {
		pc = pa;
		pa = pa->next;
	}
	else {
		pc = pb;
		pb = pb->next;
	}
	*Lc=pc;
	while (pa&&pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	//free(*Lb);
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
	printf("����ǰ��la��lb\n");
	printf("la:\n");
	ListTraverse(La, MyVisit);
	printf("lb:\n");
	ListTraverse(Lb, MyVisit);
	MergeList_L(&La, &Lb, &Lc);
	printf("lc:\n");
	ListTraverse(Lc, MyVisit);
	DestroyList(&Lc);
	//system("pause");
	return 0;
}