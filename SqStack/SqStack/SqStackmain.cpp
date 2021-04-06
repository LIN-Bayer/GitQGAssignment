#include<iostream>
#include"Sqstack.h"

int main()
{
	int n;
	std::cout << "��ʼ��ջ���������������ջ�Ĵ�С��" << std::endl;
	std::cin >> n;
	if (n > 25)
	{
		std::cout << "���ǵ������ʱ�����Լ����ܱ�ջ�����ⳬ��25������Ϊ��Ч" << std::endl;
		std::cout << "��ֻ������25����" << std::endl;
		n = 25;
	}
	class SqStack<int> SqStack(n);
	std::cout << "����" << n << "��Ԫ��:" << std::endl;
	for (int i = 0; i < n; ++i) {
		int data;
		std::cin >> data;
		SqStack.pushStack(data);
	}
	int choice;
	while (true)
	{
		SqStack.showMenu();
		std::cout << "������ѡ��(��Ϊ��������)" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 0:
			std::cout << "ջ�����٣�" << std::endl;
			SqStack.~SqStack();
			break;
		case 1:
		{
			int ret = SqStack.isEmptyStack();
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
			if (SqStack.isEmptyStack())
			{
				std::cout << "ջΪ�գ���ջ��Ԫ�أ�" << std::endl;
			}
			else
			{
				std::cout << "ջ��Ԫ��Ϊ��" << SqStack.getTopStack() << std::endl;
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
				SqStack.clearStack();
				std::cout << "��ճɹ���" << std::endl;
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
			if (SqStack.isEmptyStack())
			{
				std::cout << "ջΪ��" << std::endl;
			}
			else
			{
				std::cout << "ջ�ĳ���Ϊ��" << SqStack.stackLength() + 1 << std::endl;
			}
			break;
		}
		case 5:
		{
			int data;
			std::cout << "��������Ҫ��ջ����:" << std::endl;
			std::cin >> data;
			if (SqStack.isEmptyStack())
			{
				SqStack.pushStack(data);
				std::cout << "ջΪ��,��ʱ��ջ���ڵײ���" << std::endl;
			}
			else
			{
				SqStack.pushStack(data);
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
				if (SqStack.isEmptyStack())
				{
					std::cout << "ջΪ�գ��޷����г�ջ��" << std::endl;
				}
				else
				{
					SqStack.popStack();
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
			std::cout << "�������󣡲���ִ�й��ܣ�" << std::endl;
		}
		std::system("pause");
		std::system("cls");
	}
	return 0;
}