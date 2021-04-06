#include<iostream>
#include"LinkStack.h"

int main()
{
	class LinkStack<int> linkstack;
	int choice;
	while (true)
	{
		linkstack.showMenu();
		std::cout << "������ѡ��(��Ϊ��������)" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 0:
			std::cout << "ջ�����٣�" << std::endl;
			linkstack.~LinkStack();
			break;
		case 1:
		{
			int ret = linkstack.isEmptyLStack();
			if (ret == 1)
			{
				std::cout << "ջΪ�գ�" << std::endl;
			}
			else
			{
				std::cout << "ջ��Ϊ�գ�" << std::endl;
			}
			break;
		}
		case 2:
		{
			if (linkstack.isEmptyLStack())
			{
				std::cout << "ջΪ�գ���ջ��Ԫ�أ�" << std::endl;
			}
			else
			{
				std::cout << "ջ��Ԫ��Ϊ��" << linkstack.getTopLStack() << std::endl;
			}
			break;
		}
		case 3:
		{
			int a;
			std::cout << "ȷ��Ҫ���ջ��" << std::endl;
			std::cout << "1.ȷ��" << std::endl;
			std::cout << "2.ȡ��" << std::endl;
			std::cin >> a;
			if (a == 1)
			{
				if (linkstack.isEmptyLStack())
				{
					std::cout << "ջ��Ϊ�գ�����Ҫ����գ�" << std::endl;
				}
				else
				{
					linkstack.clearLStack();
					std::cout << "��ճɹ���" << std::endl;
				}
			}
			else if (a == 2)
			{
				std::cout << "ȡ����ճɹ���" << std::endl;
			}
			else
			{
				std::cout << "���������޷�ִ��" << std::endl;
			}
			break;
		}
		case 4:
		{
			if (linkstack.isEmptyLStack())
			{
				std::cout << "ջΪ��" << std::endl;
			}
			else
			{
				std::cout << "ջ�ĳ���Ϊ��" << linkstack.LStackLength() << std::endl;
			}
			break;
		}
		case 5:
		{
			int data;
			std::cout << "��������Ҫ��ջ����:" << std::endl;
			std::cin >> data;
			if (linkstack.isEmptyLStack())
			{
				linkstack.pushLStack(data);
				std::cout << "ջΪ��,��ʱ��ջ���ڵײ���" << std::endl;
			}
			else
			{
				linkstack.pushLStack(data);
				std::cout << "��ջ�ɹ���" << std::endl;
			}
			break;
		}
		case 6:
		{
			int a;
			std::cout << "ȷ��Ҫִ�г�ջ��" << std::endl;
			std::cout << "1.ȷ��" << std::endl;
			std::cout << "2.ȡ��" << std::endl;
			std::cin >> a;
			if (a == 2)
			{
				std::cout << "ȡ����ջ�ɹ���" << std::endl;
			}
			else if (a == 1)
			{
				if (linkstack.isEmptyLStack())
				{
					std::cout << "ջΪ�գ��޷����г�ջ��" << std::endl;
				}
				else
				{
					linkstack.popLStack();
					std::cout << "��ջ�ɹ���" << std::endl;
				}
			}
			else
			{
				std::cout << "���������޷����в�����" << std::endl;
			}
			break;
		}
		default:
			std::cout << "���������޷�ִ�й��ܣ�" << std::endl;
		}
		std::system("pause");
		std::system("cls");
	}
	return 0;
}