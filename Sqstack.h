#pragma once
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


template<typename T>

class SqStack
{
protected:
	T* elem;   //ջ��Ԫ��
	int top;   //����
	int size;  //����Ĺ̶�����

public:
	//���������˳��ջ
	
	void showMenu();//��ʾ�˵�

	SqStack(int sizes);//��ʼ��ջ

	bool isEmptyStack();//�ж�ջ�Ƿ�Ϊ��

	T& getTopStack(); //�õ�ջ��Ԫ��

	bool clearStack();//���ջ

	~SqStack();//��������������ջ

	T& stackLength();//���ջ����

	void pushStack(const T data);//��ջ

	void popStack();//��ջ

};


//��ʾ�˵�
template<typename T>
void SqStack<T>::showMenu()
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

//��ʼ��ջ
template<typename T>
SqStack<T>::SqStack(int sizes)
{
	top = -1;
	size = sizes;
	elem = new T[size];
}



//����ջ
template<typename T>
SqStack<T>::~SqStack()
{
	if (isEmptyStack())
	{
		std::cout << "�����Ϊ���������֣�ջ��������ϵͳ�˳���" << std::endl;
		exit(0);
	}
	else
	{
		delete[] elem;
			size = 0;
			top = -1;
	}
}

//�ж�ջ�Ƿ�Ϊ��
template<typename T>
bool SqStack<T>::isEmptyStack()
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//���ջ
template<typename T>
bool SqStack<T>::clearStack()
{
	top = -1;
	size = 0;
	return true;
}

//�õ�ջ��Ԫ��
template<typename T>
T& SqStack<T>::getTopStack()
{
	if (top == -1)
	{
		abort();
	}
	else
	{
		return elem[top];
	}
}

//���ջ�ĳ���
template<typename T>
T& SqStack<T>::stackLength()
{
	return top;
}


//��ջ
template<typename T>
void SqStack<T>::pushStack(const T data)
{
	if (stackLength()>= size)
	{
		std::cout << "ջ�������޷���ջ��" << std::endl;
		abort();
	}
	elem[++top] = data;
	size++;
	
}



//��ջ
template<typename T>
void SqStack<T>::popStack()
{
	if (isEmptyStack())
	{
		std::cout << "ջΪ�գ��޷�ִ�г�ջ������" << std::endl;
		abort();
	}
	else
	{
		top--;
	}
}



#endif 
