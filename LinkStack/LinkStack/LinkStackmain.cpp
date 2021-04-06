#include<iostream>
#include"LinkStack.h"

int main()
{
	class LinkStack<int> linkstack;
	int choice;
	while (true)
	{
		linkstack.showMenu();
		std::cout << "请输入选项(需为整型数字)" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 0:
			std::cout << "栈已销毁！" << std::endl;
			linkstack.~LinkStack();
			break;
		case 1:
		{
			int ret = linkstack.isEmptyLStack();
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
			if (linkstack.isEmptyLStack())
			{
				std::cout << "栈为空，无栈顶元素！" << std::endl;
			}
			else
			{
				std::cout << "栈顶元素为：" << linkstack.getTopLStack() << std::endl;
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
				if (linkstack.isEmptyLStack())
				{
					std::cout << "栈已为空，不需要再清空！" << std::endl;
				}
				else
				{
					linkstack.clearLStack();
					std::cout << "清空成功！" << std::endl;
				}
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
			if (linkstack.isEmptyLStack())
			{
				std::cout << "栈为空" << std::endl;
			}
			else
			{
				std::cout << "栈的长度为：" << linkstack.LStackLength() << std::endl;
			}
			break;
		}
		case 5:
		{
			int data;
			std::cout << "请输入想要入栈的数:" << std::endl;
			std::cin >> data;
			if (linkstack.isEmptyLStack())
			{
				linkstack.pushLStack(data);
				std::cout << "栈为空,此时入栈后在底部！" << std::endl;
			}
			else
			{
				linkstack.pushLStack(data);
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
				if (linkstack.isEmptyLStack())
				{
					std::cout << "栈为空！无法进行出栈！" << std::endl;
				}
				else
				{
					linkstack.popLStack();
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
			std::cout << "输入有误，无法执行功能！" << std::endl;
		}
		std::system("pause");
		std::system("cls");
	}
	return 0;
}