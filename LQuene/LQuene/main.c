#include<stdio.h>
#include <stdlib.h>
#include"LQuene.h"
#include"LQuene.c"


int main()
{
	int select, choice;
	void* data = NULL;
	LQueue* Q;
	Q = (LQueue*)malloc(sizeof(LQueue));

	printf_s("Now determine which data type the queue accesses:\n");
	printf_s(" 1.int\t 2.double\t 3.char\n");
	scanf_s("%d", &select);
	(int)select;
	while (1)
	{
		if (select == 1)
		{
			type = 'i';
			Typesize = sizeof(int);
			break;
		}
		else if (select == 2)
		{
			type = 'd';
			Typesize = sizeof(double);
			break;
		}
		else if (select == 3)
		{
			type = 'c';
			Typesize = sizeof(char);
			break;
		}
		printf_s("Incorrect input, no function to perform!\n");
		break;
	}

	if (select == 1 || select == 2 || select == 3)
	{
		InitLQueue(Q);
		printf_s("The queue has been initialized for you!\n");
		while (1)
		{
			ShowMenu();
			printf_s("Please enter your options:\n");
			scanf_s("%d", &choice);
			(int)choice;
			switch (choice)
			{
			case 1:
				DestoryLQueue(Q);
				printf_s("Queue destroyed!\n");
				break;
			case 2:
				if (IsEmptyLQueue(Q))
				{
					printf("Queue is Empty!\n");
				}
				else
				{
					printf_s("Queue is not Empty!\n");
				}
				break;
			case 3:
			{
				GetHeadLQueue(Q, &data);
				if (select == 1)
				{
					printf_s("The head elem is:%d", *(int*)data);
				}
				else if (select == 2)
				{
					printf_s("The head elem is:%.2lf", *(double*)data);
				}
				else if (select == 3)
				{
					printf_s("The head elem is:%c", *(char*)data);
				}
				break;
			}
			case 4:
			{
				if (IsEmptyLQueue(Q))
				{
					printf_s("The queue is empty.\n");
				}
				else {
					printf_s("The quene's length is:%d", LengthLQueue(Q));
				}
				break;
			}
			case 5:
			{
				printf_s("Please enter the number to join the queue:\n");
				if (select == 1)
				{
					data = (int*)malloc(Typesize);
					scanf_s("%d", (int*)data);
				}
				else if (select == 2)
				{
					data = (double*)malloc(Typesize);
					scanf_s("%lf", (double*)data);
				}
				else if (select == 3)
				{
					data = (char*)malloc(Typesize);
					getchar();//忽略回车字符
					scanf_s("%c", (char*)data, 1);
				}
				EnLQueue(Q, data);
				break;
			}
			case 6:
				DeLQueue(Q);
				break;
			case 7:
				if (IsEmptyLQueue(Q))
				{
					printf_s("The quene is empty!\n");
				}
				else
				{
					TraverseLQueue(Q, LPrint);
				}
				break;
			case 8:
				ClearLQueue(Q);
				break;
			default:
				printf_s("Incorrect input, no function to perform!\n");
				break;
			}
			system("pause");
			system("cls");
		}
	}
	return 0;
}