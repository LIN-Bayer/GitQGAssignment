#include<stdio.h>
#include <stdlib.h>
#include"AQuene.h"
#include"AQuene.c"


int main()
{
	int select, choice;
	void* data=NULL;
	AQueue* Q;
	Q = (AQueue*)malloc(sizeof(AQueue));

	printf_s("现在先确定队列要存取哪种数据类型: \n");
	printf_s(" 1.int型\t 2.double型\t 3.char型\n");
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
		printf_s("无所输选项，无法进行操作！\n");
		break;
	}

	if (select == 1 || select == 2 || select == 3)
	{
		InitAQueue(Q);
		printf_s("已为您初始化好队列！\n");
		while (1)
		{
			ShowMenu();
			printf_s("请输入你的选项：\n");
			scanf_s("%d", &choice);
			(int)choice;
			switch (choice)
			{
			case 0:
				DestoryAQueue(Q);
				printf_s("队列已销毁！\n");
				break;
			case 1:
				if (IsFullAQueue(Q))
				{
					printf_s("队列已满！\n");
				}
				else
				{
					printf_s("队列未满！\n");
				}
				break;
			case 2:
				if (IsEmptyAQueue(Q))
				{
					printf("队列为空！\n");
				}
				else
				{
					printf_s("队列不为空！\n");
				}
				break;
			case 3:
			{
				GetHeadAQueue(Q, &data);
				if (select == 1)
				{
					printf_s("队头元素为：%d", *(int*)data);
				}
				else if (select == 2)
				{
					printf_s("队头元素为：%.2lf", *(double*)data);
				}
				else if (select == 3)
				{
					printf_s("队头元素为：%c", *(char*)data);
				}
				break;
			}
			case 4:
			{
				if (IsEmptyAQueue(Q))
				{
					printf_s("队列为空。\n");
				}
				else {
					printf_s("%d", LengthAQueue(Q));
				}
				break;
			}
			case 5:
			{
				printf_s("请输入要入队的数值：\n");
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
				EnAQueue(Q, data);
				break;
			}
			case 6:
				DeAQueue(Q);
				break;
			case 7:
				TraverseAQueue(Q, APrint);
				break;
			case 8:
				ClearAQueue(Q);
				break;
			default:
				printf_s("输入有误，无可执行功能！\n");
				break;
			}
			system("pause");
			system("cls");
		}
	}
	return 0;
}