/*1650254 ��Ң�� �����һ��*/
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

/* P.28 ��ʽ���� */
typedef int ElemType;	//�ɸ�����Ҫ�޸�Ԫ�ص�����

typedef struct LNode {
	ElemType      data;	//�������
	struct LNode *next;	//���ֱ�Ӻ�̵�ָ��
} LNode, *LinkList;

