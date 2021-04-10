#include<stdio.h>
#include <stdlib.h>
#include"AQuene.h"


//显示菜单
inline void ShowMenu()
{
	printf_s("**************************************\n");
	printf_s("************0.销毁队列****************\n");
	printf_s("************1.检查队列是否已满********\n");
	printf_s("************2.检查队列是否为空********\n");
	printf_s("************3.查看队头元素************\n");
	printf_s("************4.队列的长度**************\n");
	printf_s("************5.入队********************\n");
	printf_s("************6.出队********************\n");
	printf_s("************7.遍历队列****************\n");
	printf_s("************8.清空队列****************\n");
	printf_s("**************************************\n");
}

//初始化队列
inline void InitAQueue(AQueue* Q)
{
	int i;
	Q->length = MAXQUEUE;
	for (i = 0; i < MAXQUEUE; i++) {
		Q->data[i] = (void*)malloc(Typesize);
	}
	Q->front = Q->rear = 0;

}

//销毁队列
inline void DestoryAQueue(AQueue* Q)
{
	for (int i = 0; i < MAXQUEUE; i++) {
		free(Q->data[i]);
	}
	Q->data[0] = NULL;
}

//检查队列是否已满
inline Status IsFullAQueue(const AQueue* Q)
{
	if (LengthAQueue(Q) == MAXQUEUE - 1)
	{
		return TRUE;
	}
	else
		return FALSE;

}

//判断队列是否为空
inline Status IsEmptyAQueue(const AQueue* Q)
{
	if (LengthAQueue(Q) == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}




//查看队头元素
inline Status GetHeadAQueue(AQueue* Q, void* e)
{
	if (IsEmptyAQueue(Q))
	{
		printf_s("队列为空,不存在队头元素！\n");
		return FALSE;
	}
	// 直接传值的地址
	e = Q->data[Q->front];
	return TRUE;
}


//确定队列长度
inline int LengthAQueue(AQueue* Q)
{
	return (Q->rear - Q->front + Q->length) % Q->length;
}

//入队
inline Status EnAQueue(AQueue* Q, void* data)
{

	if (IsFullAQueue(Q))
	{
		printf_s("队列已满，无法进行入队操作!\n");
		return FALSE;
	}
	if (IsEmptyAQueue(Q))
	{
		memcpy(Q->data[Q->front], data, Typesize);
		Q->rear = (Q->rear + 1) % Q->length;
		printf("入队成功！");
		return TRUE;
	}
	memcpy(Q->data[Q->rear], data, Typesize);
	Q->rear = (Q->rear + 1) % Q->length;
	printf("入队成功！");
	return TRUE;
}

//出队
inline Status DeAQueue(AQueue* Q)
{
	if (IsEmptyAQueue(Q))
	{
		printf_s("队列为空，无法进行出队操作！\n");
		return FALSE;
	}
	Q->front = (Q->front + 1) % Q->length;
	printf("出队成功！");
	return TRUE;
}

//清空队列
inline void ClearAQueue(AQueue* Q)
{
	if (IsEmptyAQueue(Q))
	{
		printf_s("队列为空，不用进行清空操作！\n");
		return;
	}
	Q->front = Q->rear = 0;
}

//遍历函数操作
inline Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q))
{
	if (IsEmptyAQueue(Q))
	{
		printf_s("队列为空!\n");
		return FALSE;
	}
	int i;
	for (int i = Q->front, j = 0; j <LengthAQueue(Q); j++)
	{
		foo(Q->data[i]);
		printf(" ");
		i = (i + 1) % MAXQUEUE;
	}
	return TRUE;
}

//操作函数
inline void APrint(void* q)
{
	if (type == 'i')
		printf_s("%d", *((int*)q));
	else if (type == 'd')
		printf_s("%.2lf", *((double*)q));
	else if (type == 'c')
		printf_s("%c", *((char*)q));

}