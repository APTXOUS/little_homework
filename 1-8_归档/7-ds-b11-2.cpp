/*1650254 ��Ң�� �����һ��*/
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
int line_count = 0;   //��ӡ����ʱ�ļ�����
					  /* P.28 ��ʽ���� */
typedef int ElemType;	//�ɸ�����Ҫ�޸�Ԫ�ص�����

typedef struct LNode {
	ElemType      data;	//�������
	struct LNode *next;	//���ֱ�Ӻ�̵�ָ��
	struct LNode *prior;
} LNode, *LinkList;

Status InitList(LinkList *L)
{
	*L = (LNode *)malloc(sizeof(LNode));
	if (*L == NULL)
		exit(OVERFLOW);
	(*L)->next = *L;
	(*L)->prior = *L;
	return OK;
}

/* ɾ��ѭ������ */
Status DestroyList(LinkList *L)
{
	LinkList q, p = (*L)->next; //ָ����Ԫ

								/* ��������(��ͷ���)�����ͷ� */
	while (p != *L) {    //������Ϊ�գ���ѭ����ִ��
		q = p->next; //ץס�������һ�����
		free(p);
		p = q;
	}

	*L = NULL;	//ͷָ����NULL
	return OK;
}



/* ���ĳ��� */
int ListLength(LinkList L)
{
	LinkList p = L->next; //ָ����Ԫ���
	int len = 0;

	/* ѭ�������������м��� */
	while (p != L) {
		p = p->next;
		len++;
	}

	return len;
}

/* ��ָ��λ��ǰ����һ����Ԫ�� */
Status ListInsert(LinkList *L, int i, ElemType e)
{
	LinkList s, p;
	p = (*L);	//pָ��ͷ���
	int   pos = 0;

	/* Ѱ�ҵ�i-1����� */
	while (p->next != *L && pos<i - 1) {
		p = p->next;
		pos++;
	}

	if (p == NULL || pos>i - 1)  //iֵ�Ƿ��򷵻�
		return ERROR;

	//ִ�е��˱�ʾ�ҵ�ָ��λ�ã�pָ���i-1�����

	s = (LinkList)malloc(sizeof(LNode));
	if (s == NULL)
		return OVERFLOW;

	s->data = e; 	//�½��������ֵ
	s->next = p->next;	//�½���next�ǵ�i��
	p->next = s;	//��i-1����next���½��
	s->prior = p;
	s->next->prior = s;
	return OK;
}
/* ɾ��ָ��Ԫ�أ�������ɾ��Ԫ�ص�ֵ����e�з��� */
Status ListDelete(LinkList *p, ElemType *e)
{
	(*p)->next->prior = (*p)-> prior;
	(*p)->prior->next = (*p)->next;
	*e = (*p)->data;      //ȡ��i������ֵ
	LinkList q= (*p);
	(*p) = (*p)->next;
	free(q);           //�ͷŵ�i�����
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
void NEXT(LinkList *e)
{
	*e = (*e)->prior;
	//*e = (*e)->next;
}
/* �������Ա� */
Status ListTraverse(LinkList L, Status(*visit)(ElemType e),void (*next)(LinkList *e))
{
	extern int line_count; //��main�ж���Ĵ�ӡ���м����������㷨�޹أ�
	LinkList p = L;
	NEXT(&p);

	line_count = 0;		//�������ָ���ʼֵ�����㷨�޹أ�
	while (p != L && (*visit)(p->data) == TRUE)
		NEXT(&p);

	if (p != L)
		return ERROR;

	printf("\n");//����ӡһ�����У�ֻ��Ϊ�˺ÿ������㷨�޹�
	return OK;
}

/*ѭ������*/
Status ListTravel(LinkList *L, int k, int m)
{
	LinkList  p;
	p = (*L);	//pָ��ͷ���
	int   pos = 0;

	/* Ѱ�ҵ�i-1����� */
	while (pos<m) {
		NEXT(&p);
		if (p == *L)
			NEXT(&p);
		printf("%d->", p->data);
		pos++;
	}
	printf("\n**************\n");
	pos = 1;
	while (ListLength(*L) != 1)
	{
		printf("STEP:");
		while (pos < k)
		{
			if (p->prior == *L)
			{
				NEXT(&p);
			}
			NEXT(&p);
			printf("%d->", p->data);
			pos++;
		}
		if (p== *L)
			NEXT(&p);
		int e;
		ListDelete(&p, &e);
		printf("delete:%d->\n", e);
		ListTraverse(*L, MyVisit, NEXT);
		printf("**************\n\n");
		pos = 0;

	}
	printf("the last person: %d->\n", (*L)->prior->data);
	return OK;
}
int main()
{
	int n, m, k;
	printf("������n,m,k��ֵ\n");
	scanf("%d%d%d", &n, &m, &k);
	LinkList head;
	InitList(&head);
	for (int i = 1; i <= n; i++)
	{
		ListInsert(&head, 1, i);
	}
	ListTraverse(head, MyVisit, NEXT);
	
	ListTravel(&head, k, m);
	DestroyList(&head);
	//system("pause");
	return 0;
}
