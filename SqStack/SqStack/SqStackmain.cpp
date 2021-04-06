#include<iostream>
#include"Sqstack.h"

int main()
{
	int n;
	std::cout << "初始化栈，首先输入所需的栈的大小：" << std::endl;
	std::cin >> n;
	if (n > 25)
	{
		std::cout << "考虑到输入费时费力以及可能爆栈的问题超过25的数视为无效" << std::endl;
		std::cout << "你只能输入25个数" << std::endl;
		n = 25;
	}
	class SqStack<int> SqStack(n);
	std::cout << "输入" << n << "个元素:" << std::endl;
	for (int i = 0; i < n; ++i) {
		int data;
		std::cin >> data;
		SqStack.pushStack(data);
	}
	int choice;
	while (true)
	{
		SqStack.showMenu();
		std::cout << "请输入选项(需为整型数字)" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 0:
			std::cout << "栈已销毁！" << std::endl;
			SqStack.~SqStack();
			break;
		case 1:
		{
			int ret = SqStack.isEmptyStack();
			if (ret == 1)
			{
				std::cout << "栈为空！" << std::endl;
			}
			else
			{
				std::cout << "栈不为空！" << std::endl;
			}
			break;
		}
		case 2:
		{
			if (SqStack.isEmptyStack())
			{
				std::cout << "栈为空，无栈顶元素！" << std::endl;
			}
			else
			{
				std::cout << "栈顶元素为：" << SqStack.getTopStack() << std::endl;
			}
			break;
		}
		case 3:
		{
			int a;
			std::cout << "确定要清空栈吗？" << std::endl;
			std::cout << "1.确定" << std::endl;
			std::cout << "2.取消" << std::endl;
			std::cin >> a;
			if (a == 1)
			{
				SqStack.clearStack();
				std::cout << "清空成功！" << std::endl;
			}
			else if (a == 2)
			{
				std::cout << "取消清空成功！" << std::endl;
			}
			else
			{
				std::cout << "输入有误！无法执行" << std::endl;
			}
			break;
		}
		case 4:
		{
			if (SqStack.isEmptyStack())
			{
				std::cout << "栈为空" << std::endl;
			}
			else
			{
				std::cout << "栈的长度为：" << SqStack.stackLength() + 1 << std::endl;
			}
			break;
		}
		case 5:
		{
			int data;
			std::cout << "请输入想要入栈的数:" << std::endl;
			std::cin >> data;
			if (SqStack.isEmptyStack())
			{
				SqStack.pushStack(data);
				std::cout << "栈为空,此时入栈后在底部！" << std::endl;
			}
			else
			{
				SqStack.pushStack(data);
				std::cout << "入栈成功！" << std::endl;
			}
			break;
		}
		case 6:
		{
			int a;
			std::cout << "确定要执行出栈吗？" << std::endl;
			std::cout << "1.确定" << std::endl;
			std::cout << "2.取消" << std::endl;
			std::cin >> a;
			if (a == 2)
			{
				std::cout << "取消出栈成功！" << std::endl;
			}
			else if (a == 1)
			{
				if (SqStack.isEmptyStack())
				{
					std::cout << "栈为空！无法进行出栈！" << std::endl;
				}
				else
				{
					SqStack.popStack();
					std::cout << "出栈成功！" << std::endl;
				}
			}
			else
			{
				std::cout << "输入有误，无法进行操作！" << std::endl;
			}
			break;
		}
		default:
			std::cout << "输入有误！不可执行功能！" << std::endl;
		}
		std::system("pause");
		std::system("cls");
	}
	return 0;
}