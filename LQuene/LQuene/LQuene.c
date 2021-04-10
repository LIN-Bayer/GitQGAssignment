#include<stdio.h>
#include <stdlib.h>
#include"LQuene.h"



//显示菜单
inline void ShowMenu()
{
	printf_s("**************************************\n");
	printf_s("************1.Destory    *************\n");
	printf_s("************2.IsEmpty    *************\n");
	printf_s("************3.Head       *************\n");
	printf_s("************4.Length     *************\n");
	printf_s("************5.Push       *************\n");
	printf_s("************6.Pop        *************\n");
	printf_s("************7.Traverse   *************\n");
	printf_s("************8.clear      *************\n");
	printf_s("**************************************\n");
}


//初始化队列
inline void InitLQueue(LQueue* Q)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (NULL == p)
		return;
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
	return;
}


//销毁队列
inline void DestoryLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
		return;
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
}

//检查队列是否为空
inline Status IsEmptyLQueue(const LQueue* Q) 
{
	if (LengthLQueue(Q) == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


//队列长度
inline int LengthLQueue(LQueue* Q)
{
	int length;
	Node* p = (Node*)malloc(sizeof(Node));
	p = Q->front;
	for (length = 0; p != Q->rear; length++)
		p = p->next;
	return length;
}


//队头元素
inline Status GetHeadLQueue(LQueue* Q, void* e) 
{
	if (IsEmptyLQueue(Q))
	{
		printf_s("The queue is empty, no header element exists!\n");
		return FALSE;
	}
	e = Q->front->next->data;
	return TRUE;
}


//入队
inline Status EnLQueue(LQueue* Q, void* data)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (NULL == p)
		return FALSE;
	p->data = (void*)malloc(Typesize);
	p->data = data;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return TRUE;
}


//出队
inline Status DeLQueue(LQueue* Q) 
{
	if (IsEmptyLQueue(Q))
	{
		printf_s("The queue is empty , cannot execute!\n");
		return FALSE;
	}
	Node* p = (Node*)malloc(sizeof(Node));
	p = Q->front->next;
	Q->front->next = p->next;
	if (NULL == Q->front->next)
		Q->rear = Q->front;
	free(p);
	return TRUE;
}



//清空队列
inline void ClearLQueue(LQueue* Q) 
{
	if (IsEmptyLQueue(Q))
	{
		printf_s("The queue is empty ,don't need to clear!\n");
		return;
	}
	Node* p, * q;
	Q->rear = Q->front;
	p = Q->front->next;
	while (NULL != p) {
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	return;
}



//遍历队列
inline Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q))
{
	if (IsEmptyLQueue(Q))
		return FALSE;
	Node* p = (void*)malloc(Q->length);
	p = Q->front->next;
	int i = 1;
	while (p != NULL)
	{
		if (i % 5 == 0)
			printf("\n");
		foo(p->data);
		printf_s(" ");
		p = p->next;
		i++;
	}
	printf("\n");
	return TRUE;
}



//操作函数
inline void LPrint(void* q) 
{
	if (type == 'i')
		printf_s("%d", *((int*)q));
	else if (type == 'd')
		printf_s("%.2lf", *((double*)q));
	else if (type == 'c')
		printf_s("%c", *((char*)q));

	
}