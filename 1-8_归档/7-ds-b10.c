/*1650254 尤尧寅 计算机一班*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include<math.h>
#define MAX_NUM_PER_LINE 	10	
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define oVERFLOW	-2
int line_count = 0;
typedef int Status;
typedef double ele_coef;
typedef int ele_expn;
typedef struct polynode {
	ele_coef coef;
	ele_expn expn;
	struct polynode *next;
}polynode, *polynomial;
Status InitList(polynomial *L)
{
	/* 申请头结点空间，赋值给头指针 */
	*L = (polynomial)malloc(sizeof(polynode));
	if (*L == NULL)
		return oVERFLOW;
	(*L)->next = NULL;
	return OK;
}
Status ListTraverse(polynomial L, Status(*visit)(ele_coef coef, ele_expn expn))
{
	extern int line_count; //在main中定义的打印换行计数器（与算法无关）
	polynomial p = L;
	p = p->next;
	line_count = 0;		//计数器恢复初始值（与算法无关）
	while (p != NULL && (*visit)(p->coef, p->expn) == TRUE)
		p = p->next;

	if (p)
		return ERROR;

	printf("\n");//最后打印一个换行，只是为了好看，与算法无关
	return OK;
}
Status MyVisit(ele_coef coef, ele_expn expn)
{
	if (line_count % 5 == 0)
		printf("\n");
	printf("(%lf)x^%d+", coef, expn);
	line_count++;
	return OK;
}
ele_coef add(ele_coef e1, ele_coef e2)
{
	return  e1 + e2;
}
ele_coef minus(ele_coef e1, ele_coef e2)
{
	return  e1 - e2;
}
//***********************核心*******************************
Status polynode_add(polynomial *La, polynomial *Lb, ele_coef(*cal)(ele_coef e1, ele_coef e2))
{
	polynomial pre, p, q;
	pre = *La;
	p = (*La)->next;
	q = (*Lb)->next;
	while (p&&q)
	{
		if (p->expn < q->expn)
		{
			pre = p;
			p = p->next;
		}
		else if (p->expn == q->expn)
		{
			double x = cal(p->coef, q->coef);
			if (fabs(x) > 1e-6)
			{
				p->coef = x;
				pre = p;
			}
			else
			{
				pre->next = p->next;
				free(p);
			}
			p = pre->next;
			polynomial u;
			u = q;
			q = q->next;
			free(u);
		}
		else
		{
			polynomial u;
			u = q->next;
			q->next = p;
			pre->next = q;
			pre = q;
			q = u;
		}

	}
	if (p == NULL)
	{
		pre->next = q;
	}
	else
	{
		pre->next = p;
	}
	free(*Lb);
	return OK;
}
//**********************************************************
Status polynode_create(polynomial *L, ele_coef coef, ele_expn expn)
{
	polynomial temp;
	temp = (polynomial)malloc(sizeof(polynode));
	if (temp == NULL)
		return oVERFLOW;
	polynomial ele;
	ele = (polynomial)malloc(sizeof(polynode));
	if (ele == NULL)
		return oVERFLOW;
	temp->next = ele;
	ele->coef = coef;
	ele->expn = expn;
	ele->next = NULL;
	polynode_add(L, &temp, add);
	free(temp);
	return OK;
}
Status DestroyList(polynomial *L)
{
	polynomial q, p = (*L);
	/* 从头结点开始依次释放（含头结点） */
	while (p != NULL) { //若链表为空，则循环不执行
		q = p->next;  //抓住链表的下一个结点
		free(p);
		p = q;
	}
	*L = NULL;
	return OK;
}
Status input_data(polynomial *L)
{
	printf("请输入项数N:\n");
	int N;
	double coef;
	int expn;
	scanf("%d", &N);
	InitList(L);
	for (int i = 0; i < N; i++)
	{
		printf("请输入第%d项系数N:\n", i + 1);
		scanf("%lf", &coef);
		printf("请输入第%d项指数N:\n", i + 1);
		scanf("%d", &expn);
		polynode_create(L, coef, expn);
	}
	printf("建立的多项式经化简排序后为\n");
	ListTraverse(*L, MyVisit);
	return OK;
}
void end()
{
	int end;
	printf("输入0返回");
	while (1)
	{
		scanf("%d", &end);
		if (end == 0)
			break;
	}
	system("cls");
}
int main()
{
	while (1)
	{
		printf("0.退出\n1.建立一个一元N项式\n2.建立两个一元N项式并相加\n3.建立两个一元N项式并相减\n");
		int num;
		scanf("%d", &num);
		if (num == 0)
		{
			return 0;
		}
		else if (num == 1)
		{
			polynomial L;
			input_data(&L);
			DestroyList(&L);
			end();
		}
		else if (num == 2)
		{
			printf("建立La\n");
			polynomial La;
			input_data(&La);
			printf("建立Lb\n");
			polynomial Lb;
			input_data(&Lb);

			printf("建立好的La和Lb\n");
			printf("La");
			ListTraverse(La, MyVisit);
			printf("Lb");
			ListTraverse(Lb, MyVisit);
			printf("相加后的La");
			polynode_add(&La, &Lb, add);
			ListTraverse(La, MyVisit);
			DestroyList(&La);
	//		DestroyList(&Lb);
			end();
		}
		else if (num == 3)
		{
			printf("建立La\n");
			polynomial La;
			input_data(&La);
			printf("建立Lb\n");
			polynomial Lb;
			input_data(&Lb);

			printf("建立好的La和Lb\n");
			printf("La\n");
			ListTraverse(La, MyVisit);
			printf("Lb\n");
			ListTraverse(Lb, MyVisit);
			printf("相减后的La");
			polynode_add(&La, &Lb, minus);
			ListTraverse(La, MyVisit);
			DestroyList(&La);
	//		DestroyList(&Lb);
			end();
		}
	}
	return 0;

}