/*1650254 ��Ң�� �����һ��*/
#include <stdio.h>
#include <stdlib.h>		//malloc/realloc����
#include <unistd.h>		//exit����
#include "linear_list_L.h"	//��ʽ����

/* ��ʼ�����Ա� */
Status InitList(LinkList *L)
{
	/* ����ͷ���ռ䣬��ֵ��ͷָ�� */
	*L = (LNode *)malloc(sizeof(LNode));
	if (*L == NULL)
		exit(OVERFLOW);

	(*L)->next = NULL;
	return OK;
}

/* ɾ�����Ա� */
Status DestroyList(LinkList *L)
{
	LinkList q, p = *L; //ָ����Ԫ
						/* ��������(��ͷ���)�����ͷ� */
	while (p) {    //������Ϊ�գ���ѭ����ִ��
		q = p->next; //ץס�������һ�����;
#if defined (ELEMTYPE_IS_CHAR_P)
		free(p->data);
#endif
		free(p);
		p = q;
	}

	*L = NULL;	//ͷָ����NULL
	return OK;
}

/* ������Ա�����ͷ��㣩 */
Status ClearList(LinkList *L)
{
	LinkList q, p = (*L)->next;

	/* ����Ԫ��㿪ʼ�����ͷ� */
	while (p) {
		q = p->next;   //ץס�������һ�����
#if defined (ELEMTYPE_IS_CHAR_P)
		free(p->data);
#endif
		free(p);
		p = q;
	}

	(*L)->next = NULL; //ͷ����next����NULL
	return OK;
}

/* �ж��Ƿ�Ϊ�ձ� */
Status ListEmpty(LinkList L)
{
	/* �ж�ͷ����next�򼴿� */
	if (L->next == NULL)
		return TRUE;
	else
		return FALSE;
}

/* ���ĳ��� */
int ListLength(LinkList L)
{
#if 1
	LinkList p = L->next; //ָ����Ԫ���
	int len = 0;

	/* ѭ�������������м��� */
	while (p) {
		p = p->next;
		len++;
	}

	return len;
#else
	int len = 0;

	LinkList p = L;
	while ((p = p->next) != NULL)
		len++;

	return len;
#endif
}

/* ȡ����Ԫ�� */
Status GetElem(LinkList L, int i, ElemType *e)
{
	LinkList p = L->next;	//ָ����Ԫ���
	int    pos = 1;		//��ʼλ��Ϊ1

						/* ����ΪNULL �� δ����i��Ԫ�� */
	while (p != NULL && pos<i) {
		p = p->next;
		pos++;
	}

	if (!p || pos>i)
		return ERROR;

	/* ѭ���Ƚ��������Ա� */
#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
	strcpy(*e, p->data);	//�±��0��ʼ����i��ʵ����elem[i-1]��
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
	memcpy(e, &(p->data), sizeof(ElemType));  //�±��0��ʼ����i��ʵ����elem[i-1]��
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
	memcpy(*e, p->data, sizeof(ET))//�±��0��ʼ����i��ʵ����elem[i-1]��
#else	//int��doubleֱ�Ӹ�ֵ
	*e = p->data;		//�±��0��ʼ����i��ʵ����elem[i-1]��
#endif
	return OK;
}

/* ���ҷ���ָ��������Ԫ�� */
int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType e1, ElemType e2))
{
	LinkList p = L->next;	//��Ԫ���
	int    pos = 1;		//��ʼλ��

						/* ѭ����������  */
	while (p && (*compare)(e, p->data) == FALSE) {
		p = p->next;
		pos++;
	}

	return p ? pos : 0;
}

/* ���ҷ���ָ��������Ԫ�ص�ǰ��Ԫ�� */
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
#if 1
	LinkList p = L->next;	//ָ����Ԫ���

	if (p == NULL)	//�ձ�ֱ�ӷ���
		return ERROR;

	/* �ӵ�2����㿪ʼѭ����������(����Ƚ���ȣ���֤��ǰ��) */
#ifdef ELEMTYPE_IS_DOUBLE
	while (p->next && fabs(p->next->data - cur_e) >= 1e-6) {
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
	while (p->next  && strcmp(p->next->data, cur_e)) {
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
	while (p->next && p->next->data.num != cur_e.num) {
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
	while (p->next && p->next->data->num != cur_e->num) {
#else	//ȱʡ����int����
	while (p->next && p->next->data != cur_e) {
#endif
		p = p->next;
	}
	if (p->next == NULL) //δ�ҵ�
		return ERROR;

#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined(ELEMTYPE_IS_CHAR_P)
	strcpy(*pre_e, p->data);	//ȡǰ��Ԫ�ص�ֵ
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
	memcpy(pre_e, &(p->data), sizeof(ElemType));	//ȡǰ��Ԫ�ص�ֵ
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
	memcpy(*pre_e, (p->data) , sizeof(ET));	//ȡǰ��Ԫ�ص�ֵ
#else	//int��doubleֱ�Ӹ�ֵ
	*pre_e = p->data;	//ȡǰ��Ԫ�ص�ֵ
#endif
	return OK;
#else
	LinkList p = L; //ָ��ͷ���

					/* ѭ�����������Ƚ�ֵ�Ƿ���� */
	while (p->next && p->next->data != cur_e)
		p = p->next;

	if (p->next == NULL || p == L) //δ�ҵ�����Ԫ����ձ�
		return ERROR;
	*pre_e = p->data;
	return OK;
#endif
}

/* ���ҷ���ָ��������Ԫ�صĺ��Ԫ�� */
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
	LinkList p = L->next;  //��Ԫ���

	if (p == NULL)	//�ձ�ֱ�ӷ���
		return ERROR;
#ifdef ELEMTYPE_IS_DOUBLE
	while (p->next && fabs(p->data - cur_e) >= 1e-6) {
#elif defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
	while (p->next  && strcmp(p->data, cur_e)) {
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
	while (p->next && p->data.num != cur_e.num) {
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
	while (p->next && p->data->num != cur_e->num) {
#else	//ȱʡ����int����
	while (p->next && p->data != cur_e) {
#endif
		p = p->next;
	}
	/* �к�̽���ҵ�ǰ���ֵ����ʱ���� */
	if (p->next == NULL)
		return ERROR;
#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
	strcpy(*next_e, p->next->data);	//ȡ���Ԫ�ص�ֵ
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
	memcpy(next_e, &(p->next->data), sizeof(ElemType));	//ȡ���Ԫ�ص�ֵ
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
	memcpy(*next_e, (p->next->data), sizeof(ET));	//ȡ���Ԫ�ص�ֵ
#else	//int��doubleֱ�Ӹ�ֵ
	*next_e = p->next->data;	//ȡ���Ԫ�ص�ֵ
#endif

	return OK;
}

/* ��ָ��λ��ǰ����һ����Ԫ�� */
Status ListInsert(LinkList *L, int i, ElemType e)
{
	LinkList s, p = *L;	//pָ��ͷ���
	int      pos = 0;

	/* Ѱ�ҵ�i-1����� */
	while (p && pos<i - 1) {
		p = p->next;
		pos++;
	}

	if (p == NULL || pos>i - 1)  //iֵ�Ƿ��򷵻�
		return ERROR;

	//ִ�е��˱�ʾ�ҵ�ָ��λ�ã�pָ���i-1�����

	s = (LinkList)malloc(sizeof(LNode));
	if (s == NULL)
		return OVERFLOW;
#if defined (ELEMTYPE_IS_CHAR_ARRAY)
	strcpy(s->data, e);
#elif defined (ELEMTYPE_IS_CHAR_P)
	/* ԭ��L->elem[i-1]��ָ���ѷ���[i]�У�Ҫ��������ռ䣬������Ԫ�أ�����+1 */
	s->data = (ElemType)malloc((strlen(e) + 1) * sizeof(char));
	if (s->data == NULL)
		return LOVERFLOW;

	strcpy(s->data, e);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
	memcpy(&(s->data), &e, sizeof(ElemType));
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
	s->data = (ElemType)malloc(sizeof(ET));
	if (s->data == NULL)
		return overflow;
	memcpy(s->data, e, sizeof(ET));
#else	//int��doubleֱ�Ӹ�ֵ
	s->data = e;
#endif
		//�½��������ֵ
	s->next = p->next;	//�½���next�ǵ�i��
	p->next = s;	//��i-1����next���½��

	return OK;
}

/* ɾ��ָ��λ�õ�Ԫ�أ�������ɾ��Ԫ�ص�ֵ����e�з��� */
Status ListDelete(LinkList *L, int i, ElemType *e)
{
	LinkList q, p = *L;	//pָ��ͷ���
	int      pos = 0;

	/* Ѱ�ҵ�i����㣨p->next�ǵ�i����㣩 */
	while (p->next && pos<i - 1) {
		p = p->next;
		pos++;
	}

	if (p->next == NULL || pos>i - 1)	//iֵ�Ƿ��򷵻�
		return ERROR;

	//ִ�е��˱�ʾ�ҵ��˵�i����㣬��ʱpָ���i-1�����

	q = p->next;       //qָ���i�����
	p->next = q->next; //��i-1������next��ָ���i+1��

#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
	strcpy(*e, q->data);	//�±��0��ʼ����i��ʵ����elem[i-1]��
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
	memcpy(e, &(q->data), sizeof(ElemType)); //�±��0��ʼ����i��ʵ����elem[i-1]��
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
	memcpy(*e, q->data, sizeof(ET)); //�±��0��ʼ����i��ʵ����elem[i-1]��
#else	//int��doubleֱ�Ӹ�ֵ
	*e = q->data;  //�±��0��ʼ����i��ʵ����elem[i-1]��
#endif
	
#if defined (ELEMTYPE_IS_CHAR_P)

	/* �����ͷŶ����ռ� */
	free(q->data);
#endif
	//ȡ��i������ֵ
	free(q);           //�ͷŵ�i�����

	return OK;
}

/* �������Ա� */
Status ListTraverse(LinkList L, Status(*visit)(ElemType e))
{
	extern int line_count; //��main�ж���Ĵ�ӡ���м����������㷨�޹أ�
	LinkList p = L->next;

	line_count = 0;		//�������ָ���ʼֵ�����㷨�޹أ�
	while (p && (*visit)(p->data) == TRUE)
		p = p->next;

	if (p)
		return ERROR;

	printf("\n");//����ӡһ�����У�ֻ��Ϊ�˺ÿ������㷨�޹�
	return OK;
}
