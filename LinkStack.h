#pragma once
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


template<typename T>
class LinkStack
{
	struct StackNode
	{
		T data;
		StackNode* next;
	};
protected:
	StackNode* top;//ջ��ָ��
	int	count = 0;//��ʼ��ջ��Ԫ�ظ���

public:
	//��ջ

	void showMenu();//��ʾ�˵�

	LinkStack();//��ʼ��ջ

	bool isEmptyLStack();//�ж�ջ�Ƿ�Ϊ��

	T& getTopLStack();//�õ�ջ��Ԫ��

	bool clearLStack();//���ջ

	~LinkStack();//����ջ

	T& LStackLength();//���ջ����

	void pushLStack(T data);//��ջ

	T& popLStack();//��ջ
};


//��ʾ�˵�
template<typename T>
void LinkStack<T>::showMenu()
{
	std::cout << "***********************************" << std::endl;
	std::cout << "*************0.����ջ**************" << std::endl;
	std::cout << "*********1.�ж�ջ�Ƿ�Ϊ��**********" << std::endl;
	std::cout << "**********2.�õ�ջ��Ԫ��***********" << std::endl;
	std::cout << "*************3.���ջ**************" << std::endl;
	std::cout << "**********4.���ջ�ĳ���***********" << std::endl;
	std::cout << "***************5.��ջ**************" << std::endl;
	std::cout << "***************6.��ջ**************" << std::endl;
	std::cout << "***********************************" << std::endl;
}


//��ʼ����ջ
template<typename T>
LinkStack<T>::LinkStack()
{
	top = nullptr;
}


//������ջ
template<typename T>
LinkStack<T>::~LinkStack()
{
	StackNode* p = this->top, * q;
	if (isEmptyLStack())
	{
		std::cout << "�����Ϊ���������֣�ջ��������ϵͳ�˳���" << std::endl;
		exit(0);
	}
	while (p != nullptr)
	{
		q = p->next;
		delete p;
		p = q;
	}
}


//�ж�ջ�Ƿ�Ϊ��
template<typename T>
bool LinkStack<T>::isEmptyLStack()
{
	if (top == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//�õ�ջ��Ԫ��
template<typename T>
T& LinkStack<T>::getTopLStack()
{
	if (isEmptyLStack())
	{
		abort();
	}
	else
	{
		return top->data;
	}
}


//���ջ
template<typename T>
bool LinkStack<T>::clearLStack()
{
	StackNode* p = nullptr;
	if (top == nullptr)
	{
		abort();
	}
	while (top)
	{
		p = top;
		top = top->next;
		delete p;
	}
	return true;
}


//���ջ�ĳ���
template<typename T>
T& LinkStack<T>::LStackLength()
{
	if (top == nullptr)
	{
		abort();
	}
	else
	{
		return count;
	}
}


//��ջ
template<typename T>
void LinkStack<T>::pushLStack(T data)
{
	StackNode* p = new StackNode();
	p->data = data;
	if (top == nullptr)
	{
		top = p;
	}
	else
	{
		p->next = top;
		top = p;
	}
	count++;
}


//��ջ
template<typename T>
T& LinkStack<T>::popLStack()
{
	if (top == nullptr)
	{
		abort();
	}
	else
	{
		StackNode* p = top;
		T elem = top->data;
		top = top->next;
		delete p;
		return elem;
	}
}

#endif 